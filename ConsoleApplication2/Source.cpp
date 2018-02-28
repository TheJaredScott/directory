#include <map>
#include <set>
#include <iostream>
#include <string>


using namespace std;

//global variables for ease of access.

multimap<string, multimap<string, string>> directory;
multimap<string, multimap<string, string>> company;
string decider;
string innerdecider;
int located;
string dummy;
string first;
string last;
string location;
string domain;
string position;
string address;
string phone;
multimap<string, multimap<string, string>>::iterator it;
multimap<string, string>::iterator it2;
void insert();
void companyinsert();

int main() {

	//decider keeps in loop until done with searching.
	while (decider != "4") {
		cout << "Enter 1 to insert someone, 2 to find someone, 3 to view all directories, 4 to quit: ";
		cin >> decider;
		while (decider != "1" && decider != "2" && decider != "3" && decider != "4") {
			cout << "Enter a valid value: ";
			cin >> decider;
		}

		//Takes in information to be inserted
		if (decider == "1") {
			located = 0;
			cout << "Inserting a person(1) or a company(2)? 3 to go back: ";
			cin >> innerdecider;
			while (innerdecider != "1" && innerdecider != "2" && innerdecider != "3") {
				cout << "Enter a valid value: ";
				cin >> innerdecider;
			}
			if (innerdecider == "1") {
				cout << "Enter, on seperate lines, the first name, last name, position, address, and phone of person" << "\n" << "First: ";
				getline(cin, dummy);
				getline(cin, first);
				cout << "\n" << "Last: ";
				getline(cin, last);
				cout << "\n" << "Title: ";
				getline(cin, position);
				cout << "\n" << "Address: ";
				getline(cin, address);
				cout << "\n" << "Phone: ";
				getline(cin, phone);

				//inserts into existing directory if a directory already exists. Marks as located.
				it = directory.find(last);
					if (it != directory.end()) {
						insert();
						located = 1;
					}

				//If directory was not located, create new directory containing names under new first name.
					else {
					multimap<string, string> first;
					directory.insert(make_pair(last, first));
					for (it = directory.begin(); it != directory.end(); it++)
						if (last == it->first)
							insert();


				}

			}

			if (innerdecider == "2") {
				cout << "Enter, on seperate lines, the company name, domain, address, and phone" << "\n" << "Company: ";
				getline(cin, dummy);
				getline(cin, location);
				cout << "\n" << "Domain: ";
				getline(cin, domain);
				cout << "\n" << "Address: ";
				getline(cin, address);
				cout << "\n" << "Phone: ";
				getline(cin, phone);

				//inserts into existing directory if a directory already exists. Marks as located.
				it = company.find(location);
					if (it != company.end()) {
						companyinsert();
						located = 1;
					}

				//If directory was not located, create new directory containing names under new first name.
					else{
					multimap<string, string> domain;
					company.insert(make_pair(location, domain));
					for (it = company.begin(); it != company.end(); it++)
						if (location == it->first)
							companyinsert();
				}

			}
		}

		//Searches for given full name or company
		if (decider == "2") {
				cout << "Search by Name(1) or company(2)? 3 to go back: ";
				cin >> innerdecider;
				while (innerdecider != "1" && innerdecider != "2" && innerdecider != "3") {
					cout << "Enter a valid value: ";
					cin >> innerdecider;
				}
				//Searches by first, then last name
				if (innerdecider == "1") {
					cout << "\n" << "Enter a first name, then last name, to search for" << "\n" << "First: ";
					getline(cin, dummy);
					getline(cin, first);
					cout << "\n" << "Last: ";
					getline(cin, last);
					located = 0;

					it = directory.find(last);
						if (it != directory.end()){
							it2 = it->second.find(first);
							if (it2 != it->second.end()) {
								for (it2 = it->second.begin(); it2 != it->second.end(); it2++) {
									if (it2->first == first) {
										cout << it->first << ", " << it2->first << " " << it2->second << "\n";
										located = 1;
									}
								}
							}

						}
					
					if (located == 0)
						cout << "Name not found" << "\n";

				}

				//searches by company, displays all companies with that name
				if (innerdecider == "2") {
					cout << "\n" << "Enter a company to search for" << "\n" << "Company: ";
					getline(cin, dummy);
					getline(cin, location);
					located = 0;

					it = company.find(location);
						if (it != company.end()) {
							for (it2 = it->second.begin(); it2 != it->second.end(); it2++) {
										if (it2->first == location) {
										cout << it->first << " => " << it2->first << ", " << it2->second << "\n";
										located = 1;
									}
								}

						}
					
					if (located == 0)
						cout << "Name not found" << "\n";
				}

			}
		
		//Shows all directories. Either all companies listed, or all first names of people
		if (decider == "3") {
			cout << "Display all names(1) or companies(2)? 3 to go back: " << "\n";
			cin >> innerdecider;
			while (innerdecider != "1" && innerdecider != "2" && innerdecider != "3") {
				cout << "Enter a valid value: ";
				cin >> innerdecider;
			}
			//show first names
			if (innerdecider == "1") {
				for (it = directory.begin(); it != directory.end(); it++) {
					cout << it->first << "\n";
				}
			}

			//show companies
			if (innerdecider == "2") {
				for (it = company.begin(); it != company.end(); it++) {
					cout << it->first << "\n";
				}
			}
		}
	}
	
	system("PAUSE");

	return 0;
}

//insert method for names. makes pair of lastname with other data, then inserts into map that iterator points to
void insert() {

			it->second.insert(make_pair(first, ", " + position + ", " + address + ", " + phone));
			multimap<string, string>::iterator it2 = it->second.begin();
			cout << "\n" << last << " directory contains: ";
			for (it2; it2 != it->second.end(); it2++) {
				cout << "\n" << it2->first << "" << it2->second << "\n";
			}
}

//insert method for company. makes pair of web address with other data, then inserts into map that iterator points to
void companyinsert() {

	it->second.insert(make_pair(domain, "" + address + ", " + phone));
	multimap<string, string>::iterator it2 = it->second.begin();
	cout << "\n" << location << " directory contains: ";
	for (it2; it2 != it->second.end(); it2++) {
		cout << "\n" << it2->first << ": " << it2->second << "\n";
	}

}