//
// Created by admin on 19/06/21.
//

#include <iostream>
#include "phonebook.actions.hpp"
#include "sqlite_orm.hpp"

using std::string;
using sqlite_orm::internal::storage_t;
using sqlite_orm::where;
using sqlite_orm::in;
using phonebook::PhoneBookTuple;

namespace phonebook {
	
	auto syncDbSetup(const string &path) {
		
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
		auto storage = make_storage(path + "/phonebook.db", phone_index_table);
		storage.sync_schema();
		return storage;
	}

	void insertPhoneBookIndex(const string &path, PhoneBookTuple &tuple) {
		auto storage = syncDbSetup(path);
		storage.insert(tuple);
	}
	
	void getTupleFromPhone(const string &path, const string &phoneNumber) {
		auto storage = syncDbSetup(path);
		auto result = storage.get_all<PhoneBookTuple>(
			where(
				in(&PhoneBookTuple::phone, {phoneNumber})
			)
		);
		for(auto i = result.begin(); i != result.end(); i++) {
			std::cout << (*i);
		}
	}
}