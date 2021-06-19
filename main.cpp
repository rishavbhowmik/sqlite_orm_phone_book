//
// Created by Rishav Bhowmik on 19/06/21.
//

#include <iostream>
#include "include/phonebook.tuple.hpp"
#include "include/phonebook.actions.hpp"

using std::cout;
using std::endl;

int main () {
	
	phonebook::syncDbSetup();
	
	// unit tests
	{
		// testPhoneBookTuple();
	}
	return 0;
}
