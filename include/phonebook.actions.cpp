//
// Created by admin on 19/06/21.
//

#include "phonebook.actions.hpp"
#include "sqlite_orm.hpp"

using phonebook::PhoneBookTuple;

namespace phonebook {
	void syncDbSetup() {
		
		// Columns
		using sqlite_orm::make_column;
		using sqlite_orm::autoincrement;
		using sqlite_orm::primary_key;
		using sqlite_orm::unique;
		auto id_column = make_column("id", &PhoneBookTuple::id, autoincrement(), primary_key());
		auto name_column = make_column("name", &PhoneBookTuple::name);
		auto phone_column = make_column("phone", &PhoneBookTuple::phone, unique());
		
		// Tables
		using sqlite_orm::make_table;
		auto phone_index_table = make_table("phone_index", id_column, name_column, phone_column);
		
		// DataBase
		using sqlite_orm::make_storage;
		auto storage = make_storage("/Documents/PhoneBook", phone_index_table);
		storage.sync_schema();
	}
}