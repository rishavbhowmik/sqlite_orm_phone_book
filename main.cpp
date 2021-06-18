//
// Created by Rishav Bhowmik on 19/06/21.
//

#include <iostream>
#include "include/phonebook.hpp"

using std::cout;
using std::endl;

int main () {
	PhoneBookTuple ris = newPhoneBookFromInput();
	cout << "TupleExample " << ris << endl;
	return 0;
}
