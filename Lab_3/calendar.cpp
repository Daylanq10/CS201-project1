#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// takes in the year and checks for invalid parameters
int GetYear() {

	int year;
	cout << "Enter year (must be 1000 <= x <= 9999) ==> ";
	cin >> year;
	cout << endl;

	while (year < 1000 || year > 9999) {
		cout << "Must equivalent to or greater than 1000 and less than 9999." << endl;
		cout << "Enter year (must be 1000 <= x <= 9999) ==> ";
		cin >> year;
		cout << endl;
	}
	return year;
}

// finds valid start day and assigns it to a value
int GetStartDayNumber() {

	string month;
	bool valid = false;

	do {

		cout << "What day of the year does Jan 1 fall on this year? ==> ";
		cin >> month;
		for (int i = 0; i < month.size(); ++i) {
			month.at(i) = toupper(month.at(i));
		}

		if (month == "SUNDAY") {
			return 0;
			valid = true;
		}
		else if (month == "MONDAY") {
			return 1;
			valid = true;
		}
		else if (month == "TUESDAY") {
			return 2;
			valid = true;
		}
		else if (month == "WEDNESDAY") {
			return 3;
			valid = true;
		}
		else if (month == "THURSDAY") {
			return 4;
			valid = true;
		}
		else if (month == "FRIDAY") {
			return 5;
			valid = true;
		}
		else if (month == "SATURDAY") {
			return 6;
			valid = true;
		}
		else {
			cout << "invalid input. Try again." << endl;
		}

	} while (!valid);

	cout << endl;
}

// gives days per each month and takes leap year into account
int DaysPerMonth(int MonthNumber, int Year) {

	int days;
	switch (MonthNumber) {
	

	case 0:
	case 2:
	case 4:
	case 6:
	case 7:
	case 9:
	case 11:
		return days = 31;
		break;
	case 3:
	case 5:
	case 8:
	case 10:
		return days = 30;
		break;
	case 1:
		if (Year % 4 == 0) {
				if (Year % 100 != 0) {
					return days = 29;
				}
				else if (Year % 100 == 0) {
					if (Year % 400 == 0) {
						return days = 29;
					}
					else {
						return days = 28;
					}
				}
				
		}
		else {
			return days = 28;
		}
		break;
	}
}

// prints the calendar 
void PrintOneMonth(int MonthNumber, int Year, int& StartDayNumber) {


	vector<string> months = { "January", "February", "March", "April", "May", "June",
		"July", "August", "September","October", "November", "December" };

	vector<string> days_of_week = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	string month = months.at(MonthNumber);

	cout << setw(50) << right << month << " " << Year << endl;

	cout << endl;

	for (int i = 0; i < 7; ++i) {
		cout << setw(15) << left << days_of_week[i];
	}
	cout << endl;


	for (int y = 0; y < StartDayNumber; ++y) {
		cout << setw(15) << left << " ";
	}

	for (int i = 1; i <= DaysPerMonth(MonthNumber, Year); ++i) {


		cout << setw(15) << left << i;
		if ((i + StartDayNumber) % 7 == 0) {
			cout << endl;
		}
	}
	StartDayNumber = (DaysPerMonth(MonthNumber, Year) + StartDayNumber) % 7;

	cout << endl;
	cout << endl;

}
