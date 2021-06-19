//
// Created by Rishav Bhowmik on 19/06/21.
//

#include <iostream>
#include "include/phonebook.tuple.hpp"
#include "include/phonebook.actions.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::system_error;

struct PhoneBookCli {
	static const char PATH[];
	static void add_new_contact() {
		using phonebook::newPhoneBookFromInput;
		const auto new_index = newPhoneBookFromInput();
		try {
			using phonebook::insertPhoneBookIndex;
			insertPhoneBookIndex(PhoneBookCli::PATH, new_index);
		} catch (system_error e) {
			// unique constraint error on 'phone' field
			if(e.code().value() == 19) {
				cout << "Phone Number "
					<< "\033[1;32m'" << new_index.phone << "'\033[0m"
					<< " already exists" << endl;
			} else {
				cout << "Unknown Error" << e.what() << endl;
			}
		}
	}
	static void find_phone_number() {
		using phonebook::getTupleFromPhone;
		string phone_number;
		cout << "Phone number:";
		cin >> phone_number;
		cin.ignore();
		auto [isNull, result] = getTupleFromPhone(PhoneBookCli::PATH, phone_number);
		if (isNull) {
			cout << "No contact found with Phone number "
				<< "\033[1;32m'" << phone_number << "'\033[0m"
				<< endl;
		} else {
			cout << result;
		}
	}
};
const char PhoneBookCli::PATH[] = "../Testing";

int main () {
	bool try_again = 1;
	do {
		int option = 0;
		cout << "\033[1;32mOptions:\033[0m" << endl
			<< '\t' << "\033[1;35m0:\033[0m" << " exit" << endl
			<< '\t' << "\033[1;35m1:\033[0m" << " add new contact" << endl
			<< '\t' << "\033[1;35m2:\033[0m" << " find with phone number" << endl;
		cin >> option;
		cin.ignore();
		switch (option) {
			case 0: try_again = false; break;
			case 1: PhoneBookCli::add_new_contact(); break;
			case 2: PhoneBookCli::find_phone_number(); break;
		}
	} while (try_again);
	return 0;
}
