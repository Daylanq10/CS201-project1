// Daylan Quinn
// 16227567
// 2/24/2019
// CS201R

#include <iostream> 
#include <string>
#include <vector> 
#include <fstream>
#include <iomanip>
#include "Bank.h" 
using namespace std;


int main() {

	vector<int> cust_num;				//All vectors to store file info
	vector<string> cust_firstname;
	vector<string> cust_lastname;
	vector<double> cust_savings;
	vector<double> cust_checking;
	int total = 10;					//Constant variable for size
	int num;
	double money;			//Temporary variables to add valus to vectors from file
	string name;
	bool choice = false;	//Used to loop through function


	do {

		ifstream myfile ;				//Calls opened "input.txt" as myFile
		myfile.open("input.txt");

		if (myfile.is_open()) {			//Checks if opened properly
	
			for (int i = 0; i < total; ++i) {

				myfile >> num;
				cust_num.push_back(num);
				myfile >> name;
				cust_firstname.push_back(name);
				myfile >> name;
				cust_lastname.push_back(name);			//For loop adds proper items to corresponding vectors
				myfile >> money;
				cust_savings.push_back(money);
				myfile >> money;
				cust_checking.push_back(money);
			}
			myfile.close();					//CLOSE FILE no longer needed
		}

		else {
			cout << "Unable to open file";		//incase the file did not open properly
		}

		num = MenuInput();		//Displays menu options

		switch (num) {			//Switch statement for value returned from MenuInput

		case 1:
			PrintCustomersData(cust_num, cust_firstname, cust_lastname, cust_savings, cust_checking, total);
			cout << endl;
			break;				//For option 1

		case 2:
			PrintNames(cust_num, cust_firstname, cust_lastname, total);
			cout << endl;
			break;				//For option 2

		case 3:
			PrintTotal(cust_num, cust_savings, cust_checking, total);
			cout << endl;
			break;				//For option 3

		case 4:
			choice = true;
			break;				//Ends program loop and exits
		}

	} while (!choice);

	return 0;
}
