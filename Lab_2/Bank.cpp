#include <iostream> 
#include <string>
#include <vector> 
#include <fstream>
#include <iomanip>
using namespace std;

//Checks user input ensure an integer of value 1,2,3, or 4
int MenuInput() {

	//Valuable options for display
	cout << "1.Print all customers data" << endl;
	cout << "2.Print names and IDs" << endl;
	cout << "3.Print account totals" << endl;
	cout << "4.Exit terminal" << endl;

	int option;
	bool valid = false;

	//Loop until allowable input
	do {
		cin >> option;

		switch (option) {

		case 1:
		case 2:
		case 3:
		case 4:
			valid = true;
			break;

		default:
			cout << "Invalid input. Please enter 1, 2, 3, or 4." << endl;
			break;
		}

	} while (!valid);
	cout << endl;
	return option;
}

//Uses vectors created from file to output all data

void PrintCustomersData(const vector<int> id, const vector<string> first, const vector<string> last, const vector<double> savings_account, const vector<double> checking_account, int size) {

	cout << left << setw(5) << "ID" << left << setw(10) << "First" << left << setw(10) << "Last"
		<< left << setw(10) << "Savings" << left << setw(10) << "Checkings" << endl;

	//loops through vector for output
	for (int i = 0; i <= size - 1; ++i) {

		cout << left << setw(5) << id.at(i) << left<< setw(10) << first.at(i) << left << setw(10)
			<< last.at(i) << left << setw(10) << savings_account.at(i) << left << setw(10) << checking_account.at(i) << endl;

	}
}

//Uses vectors created from file to output id and name

void PrintNames(const vector<int> id, const vector<string> first, const vector<string> last, int size) {

	cout << left << setw(5) << "ID" << left << setw(10) << "First" << left << setw(10) << "Last" << endl;

	for (int i = 0; i <= size - 1; ++i) {

		cout << left << setw(5) << id.at(i) << left << setw(10) << first.at(i) << left << setw(10) << last.at(i) << endl;
	}
}

//Uses vectors created from file to output id and both accounts seperate and together

void PrintTotal(const vector<int> id, const vector<double> savings_account, const vector<double> checking_account, int size) {

	cout << left << setw(5) << "ID" << left << setw(10) << "Savings" << left << setw(10) << "Checking" << left << setw(10) << "Total" << endl;

	double total;

	for (int i = 0; i <= size - 1; ++i) {

		total = savings_account.at(i) + checking_account.at(i);
		cout << left << setw(5) << id.at(i) << left << setw(10) << savings_account.at(i) << left << setw(10) << checking_account.at(i) << left << setw(10) << total << endl;
	}
}