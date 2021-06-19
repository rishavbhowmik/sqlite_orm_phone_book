//
// Created by Rishav Bhowmik on 19/06/21.
//

#include "phonebook.tuple.hpp"

#include <iostream>
#include <string>

using std::ostream;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::getline;

namespace phonebook {
	
	sqlite_integer defaultPhoneBookId () {
		return 0;
	}
	sqlite_text defaultPhoneBookName () {
		return "no name";
	}
	sqlite_text defaultPhoneBookPhone () {
		return "---";
	}
	
	ostream &operator<< (ostream &os, const PhoneBookTuple &pbt) {
		return os
				<< "\nPhoneBookTuple "
				<< '{' << '\n'
				<< "\tid: " << "\033[1;33m" << pbt.id << "\033[0m" << ",\n"
				<< "\tname: " << "\033[1;32m'" << pbt.name << "'\033[0m" << ",\n"
				<< "\tphone: " << "\033[1;32m'" << pbt.phone << "'\033[0m"
				<< '\n' << '}' << endl;
	}
	
	istream &operator>> (istream &is, PhoneBookTuple &pbt) {
		pbt.id = 0;
		cout << "id: -\n";
		{
			cout << "name: ";
			getline(is, pbt.name, '\n');
			is.clear();
		}
		
		{
			cout << "phone: ";
			is >> pbt.phone;
			is.ignore(1, ' ');
		}
		cout << endl;
		return is;
	}
	
	PhoneBookTuple newPhoneBookTuple (string &name, string &phone) {
		return {defaultPhoneBookId(), name, phone};
	}
	
	PhoneBookTuple defaultPhoneBookTuple () {
		return {
				defaultPhoneBookId(),
				defaultPhoneBookName(),
				defaultPhoneBookPhone()
		};
	}
	
	PhoneBookTuple newPhoneBookFromInput () {
		auto new_tuple = defaultPhoneBookTuple();
		cin >> new_tuple;
		return new_tuple;
	}
	
}

using phonebook::PhoneBookTuple;
using phonebook::newPhoneBookFromInput;

// unit tests
void testPhoneBookTuple () {
	{
		char yes;
		cout << "Start PhoneBookTuple test?";
		cin >> yes;
		if ((yes != 'y') && (yes != 'Y')) return;
	}
	for (int i = 0; i < 1; i++) {
		PhoneBookTuple ris = newPhoneBookFromInput();
		cout << "Result: " << ris << endl;
	}
}