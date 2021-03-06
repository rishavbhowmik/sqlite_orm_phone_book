//
// Created by Rishav Bhowmik on 19/06/21.
//

#ifndef SQLITE_ORM_PHONE_BOOK_PHONEBOOK_HPP
#define SQLITE_ORM_PHONE_BOOK_PHONEBOOK_HPP

#include <iostream>

using std::string;
using std::ostream;
using std::istream;

typedef int32_t sqlite_integer;
typedef string sqlite_text;

namespace phonebook {
	struct PhoneBookTuple {
		sqlite_integer id;
		sqlite_text name;
		sqlite_text phone;
		friend ostream& operator<<(ostream& os, const PhoneBookTuple& pbt);
		friend istream& operator>>(istream &is, PhoneBookTuple& pbt);
	};
	
	sqlite_integer defaultPhoneBookId();
	sqlite_text defaultPhoneBookName();
	sqlite_text defaultPhoneBookPhone();
	
	PhoneBookTuple newPhoneBookTuple(string name, string phone);
	PhoneBookTuple defaultPhoneBookTuple();
	PhoneBookTuple newPhoneBookFromInput();
}

// unit tests
void testPhoneBookTuple();

#endif //SQLITE_ORM_PHONE_BOOK_PHONEBOOK_HPP