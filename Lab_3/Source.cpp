#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include "calendar.h"

int main() {

	int year = GetYear();

	int start = GetStartDayNumber();

	cout << endl;

	// loops through 12 times for each month of year and prints month one by one
	for (int i = 0; i < 12; ++i) {
		PrintOneMonth(i, year, start);
	}

	system("pause");

	return 0;
}