// Daylan Quinn
// CS201
// 4/28/2019
// Professor Bingham

// Algorithm (shortened) : Assign base variables to give the program numbers to start with. Pass
//						  base variables into function that recursivly calls upon itself to give
//						  the proper attribute until the end of rounds or until desired number acquired.
//						  Loop to repeat program as desired.

#include <iostream>
#include <vector>
#include "Game.h"
using namespace std;

int main() {

	bool again = true;
	// LOOP FOR ENTIRE PROGRAM
	while (again) {
		//BASE VARIABLES
		int curr = 0;
		int goal = Num_Goal();
		int turns = Num_Turns();
		int tokens = 13;
		cout << endl;

		// FUNCTION THAT RUNS BASE PROGRAM
		Round(tokens, turns, goal, curr);
		// CHOICE FOR PROGRAM LOOP
		again = Again();
		cout << endl;
	}

	return 0;
}