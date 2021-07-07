// DAYLAN QUINN
// 4/15/19
// CS201R
// PROFESSOR BINGHAM

// ALGIRITHM: 1. USE EMPLOYEE BASE CLASS AS BONES FOR DERIVED CLASSES 
//(shortened) 2. CREATE DYNAMIC ARRAY OF POINTERS FROM CLASS EMPLOYEE
//			  3. OPEN FILE AND READ IN INFORMATION ONTO DYNAMIC ARRAY OF POINTERS
//			  4. CREATE SORTED OUTPUT FILE FROM DYNAMIC ARRAY 

#include <iostream>
#include "Employee.h"
#include <fstream>
#include <string>
using namespace std;

int main() {

	//CREATES DYNAMIC ARRAY OF CLASS EMPLOYEE SET TO NULL
	Employee **emp_array = new Employee*[200];
	for (int i = 0; i < 200; ++i) {
		emp_array[i] = NULL;
	}

	//OPENS INPUT FILE AND CHECKS
	ifstream fin("input.txt");
	if (!fin.fail()) {

		//USED TO TRACK TOTAL FOR ARRAY
		int hourly = 0;
		int monthly = 0;

		//UNTIL THE FILE RUNS OUT, READ DATA AND WORKED WITH WRITE TO OUTPUT TO SCREEN
		while (!fin.eof()) {
			for (int i = 0; i < 200; ++i) {
				string type;
				getline(fin, type);

				if (type == "H" || type == "h") {

					emp_array[i] = new HourlyEmployee();
					emp_array[i]->readdata(fin);
					emp_array[i]->writedata(cout);
					hourly += 1;
				}

				else if (type == "M" || type == "m") {

					emp_array[i] = new MonthlyEmployee();
					emp_array[i]->readdata(fin);
					emp_array[i]->writedata(cout);
					monthly += 1;
				}

				else if (i % 2 == 0) {
					cout << "End of file found or invalid command in file." << endl;
					fin.close();
					break;
				}
			}

		}
		//CLOSE FILE
		fin.close();
	
		//OPENS OUTPUT FILE
		ofstream fout("output.txt");

		//TOTAL FOR USE IN FOR LOOP FOR DYNAMIC ARRAY
		int total = hourly + monthly;

		//ACCIDENTALLY CREATED ARRAY TO GO EVERY 2, BUT I WORKED AROUND IT
		for (int i = 0; i < (total*2); i += 2) {
			if (emp_array[i]->gettype() == "Monthly Employee") {
				emp_array[i]->writedata(fout);
			}
		}
		for (int i = 0; i < (total * 2); i += 2) {
			if (emp_array[i]->gettype() == "Hourly Employee") {
				emp_array[i]->writedata(fout);
			}
		}

		//CLOSE OUTPUT FILE
		fout.close();
	
	}
	
	system("pause");
	return 0;
}