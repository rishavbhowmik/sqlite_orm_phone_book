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
	auto syncDbSetup(const string &path);
	void insertPhoneBookIndex(const string &path, PhoneBookTuple &tuple);
	void getTupleFromPhone(const string &path, const string &phoneNumber);
}

#endif //SQLITE_ORM_PHONE_BOOK_PHONEBOOK_ACTIONS_HPP