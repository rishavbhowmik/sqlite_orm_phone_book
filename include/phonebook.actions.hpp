//
// Created by admin on 19/06/21.
//

#ifndef SQLITE_ORM_PHONE_BOOK_PHONEBOOK_ACTIONS_HPP
#define SQLITE_ORM_PHONE_BOOK_PHONEBOOK_ACTIONS_HPP

#include "sqlite_orm.hpp"
#include "phonebook.tuple.hpp"

using sqlite_orm::internal::storage_t;
using phonebook::PhoneBookTuple;

namespace phonebook {
	struct PhoneBookTupleResult {
		bool isNull;
		PhoneBookTuple result;
	};
	auto syncDbSetup(const string &path);
	void insertPhoneBookIndex(const string &path, const PhoneBookTuple &tuple);
	PhoneBookTupleResult getTupleFromPhone(const string &path, const string &phoneNumber);
}

#endif //SQLITE_ORM_PHONE_BOOK_PHONEBOOK_ACTIONS_HPP