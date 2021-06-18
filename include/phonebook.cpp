//
// Created by Rishav Bhowmik on 19/06/21.
//

#ifndef SQLITE_ORM_PHONE_BOOK_PHONEBOOK_HPP
#define SQLITE_ORM_PHONE_BOOK_PHONEBOOK_HPP
#include "phonebook.hpp"
#endif //SQLITE_ORM_PHONE_BOOK_PHONEBOOK_HPP

#include <iostream>
#include <string>

using std::ostream;
using std::string;
using std::cout;
using std::cin;

ostream& operator<<(ostream& os, const PhoneBookTuple& pbt) {
	return os
		<< '{' << ' '
		<< "id: " << pbt.id
		<< ", name: \"" << pbt.name << '"'
		<< ", phone: \"" << pbt.phone << '"'
		<< ' ' << '}';
}

istream& operator>>(istream &is, PhoneBookTuple& pbt) {
	pbt.id = 0;
	is >> pbt.name >> pbt.phone;
	return is;
}

PhoneBookTuple newPhoneBookTuple(string& name, string& phone) {
	return { 0, name, phone };
}

const sqlite_integer DEFAULT_ID = 0;
static const sqlite_text DEFAULT_NAME = "no name";
static const sqlite_text DEFAULT_PHONE = "---";

PhoneBookTuple defaultPhoneBookTuple() {
	PhoneBookTuple newTuple { DEFAULT_ID, DEFAULT_NAME, DEFAULT_PHONE };
	return newTuple;
}

PhoneBookTuple newPhoneBookFromInput() {
	auto new_tuple = defaultPhoneBookTuple();
	 cout << "\n> name: ?\n> phone: ?\n";
	 cin >> new_tuple;
	 cin.clear();
	return new_tuple;
}
