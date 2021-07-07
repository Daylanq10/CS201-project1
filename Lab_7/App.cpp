// Daylan Quinn
// 5/09/19
// Professor Bingham
//
//	Algorithm (shortened) - 1. Create empty maps to take in the names, ratings, and multiples.
//							2. Take in file and sort to place information in correct map
//							3. Iterate through maps and output data in correct format
//							**(originaly had header and another cpp file, but seemed simple 
//							 enough without)**
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main() {

	// MAPS FOR NAMES, RATINGS, AND DUPLICATES
	map<string, double> ratings;
	map<string, int> multiples;

	// TAKES IN FILE IF IT EXIST
	ifstream fin("ratings.txt");

	// EXTRACTS FROM FILE UNTIL EMPTY
	if (!fin.fail()) {
		string total_str;
		string name;
		string rate_str;

		// TO GET TOTAL NUMBER OF RATINGS
		getline(fin, total_str);
		int total = stoi(total_str);

		// PLACES INFORMATION IN CORRECT MAP
		for (int i = 0; i < total; ++i) {
			getline(fin, name);
			getline(fin, rate_str);
			double rate = stod(rate_str);

			// IF NAME ALREADY IN MAP, ADD 1 TO MULTIPLES
			if (ratings.count(name) == 1) {
				multiples.at(name) = multiples[name] + 1;
				ratings.at(name) = ratings[name] + rate;
			}

			// NAME NOT ON MAP YET, CREATES NEW ITERATION IN BOTH MAPS
			else {
				multiples.insert(pair<string, int>(name, 1));
				ratings.insert(pair<string, double>(name, rate));
			}
		}
	}
	// CLOSE FILE
	fin.close();

	// ITERATES THROUGH BOTH MAPS AND CREATES AVERAGE RATING PLACED IN RATINGS MAP
	map<string, double>::iterator iter;
	map<string, int>::iterator iter2;
	for (iter = ratings.begin(); iter != ratings.end(); ++iter) {
		for (iter2 = multiples.begin(); iter2 != multiples.end(); ++iter2) {
			if (iter->first == iter2->first) {
				ratings.at(iter->first) = ratings.at(iter->first) / multiples.at(iter->first);
			}
		}
		
		// FORMATED OUTPUT TO BE EASILY READ
		cout << setw(20) << left << iter->first + ": "
		<< "Reviews: " << multiples[iter->first] << 
		setw(20) << right << "Average: " << iter->second << "/5" << endl;
	}	
	cout << endl;
	system("pause");
	return 0;
}