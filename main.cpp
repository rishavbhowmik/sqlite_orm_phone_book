//
// Created by Rishav Bhowmik on 19/06/21.
//

#include <iostream>
#include "include/phonebook.tuple.hpp"
#include "include/phonebook.actions.hpp"

using std::cout;
using std::endl;
using std::system_error;

int main () {
	
	// get row from phone number
	{
		phonebook::getTupleFromPhone("../Testing", "991199119911");
	}
	
	// insert new row to phone index
	{
//		auto new_index = phonebook::newPhoneBookFromInput();
//		try {
//			phonebook::insertPhoneBookIndex("../Testing", new_index);
//			cout << "New registry in the index:" << endl << new_index;
//		} catch (system_error e) {
//			if (e.code().value() == 19){
//				cout << "Phone Number "
//					<< "\033[1;32m'" << new_index.phone << "'\033[0m"
//					<< " already exists" << endl;
//			}
//		}
	}
	
	// unit tests
	{
		// testPhoneBookTuple();
	}
	return 0;
}
