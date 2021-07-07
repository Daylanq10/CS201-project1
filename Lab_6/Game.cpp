#include <iostream>
#include <vector>
#include "Game.h"
using namespace std;

// ACQUIRES THE DESIRED NUMBER OF TURNS THE USER WANTS 
int Num_Turns() {
	int num;
	do {
		cout << "How many turns would you like to play? (positive integer) ==> ";
		cin >> num;
	} while (num < 1);
	return num;
}

// ACQUIRED THE DESIRED NUMBER THAT THE USER WANTS TO FIND
int Num_Goal() {
	int goal;
	do {
		cout << "Enter the number of tokens you want to reach. (positive integer) ==> ";
		cin >> goal;
	} while (goal < 1);
	return goal;
}

// RECURSIVLY ADDS 25 OR DIVIDES BY 2
void Round(int tokens, int turns, int goal, int curr)
{
	// IF ODD REMAINDER, THEN FOLLOWS THIS IF STATEMENT
	if (tokens % 2 == 1) {
		// PROMPTS WHEN GOAL ACQUIRED
		if (tokens == goal) {
			cout << "CONGRATULATIONS! Goal of " << goal << " was acquired in " << curr << " rounds." << endl;
			cout << endl;
		// PROMPS WHEN END OF ROUNDS
		}
		else if (tokens != goal && curr >= turns) {
			cout << "FAILURE. Total of " << tokens << " found in " << turns << " rounds. Goal of " << goal << " unacheived." << endl;
			cout << endl;
		}
		// RECURSIVLY CALLS FUNCTION 'Round' AND ADDS 25 AS NEEDED
		else {
			curr += 1;
			tokens += 25;
			cout << "Adding 25, you have " << tokens << endl;
			Round(tokens, turns, goal, curr);
			}
		}
	// IF REMAINDER IS EVEN, FOLLOWS THIS STATEMENT
	else {
		// PROMPTS WHEN GOAL ACQUIRED
		if (tokens == goal) {
			cout << "CONGRATULATIONS! Goal of " << goal << " was acquired in " << curr << " rounds." << endl;
			cout << endl;
		}
		// PROMPTS WHEN END OF ROUNDS
		else if (tokens != goal && curr >= turns) {
			cout << "FAILURE. Total of " << tokens << " found in " << turns << " rounds. Goal of " << goal << " unacheived." << endl;
			cout << endl;
		}
		// RECURSIVLY CALLS 'Round' TO DIVIDE BY HALF
		else {
			curr += 1;
			tokens = tokens / 2;
			cout << "Dividing by half, you have " << tokens << endl;
			Round(tokens, turns, goal, curr);
		}
	}
}

// FINDS TRUE OR FALSE FOR PROGRAM LOOP
bool Again() {
	cout << "Want to play again? (Y)es or (N)o ==> ";
	char input;
	cin >> input;
	input = toupper(input);

	// CHECKS FOR VALID INPUT
	while (input != 'Y' && input != 'N') {
		cout << "Invalid input. Enter 'Y' or 'N' ==> ";
		cin >> input;
		input = toupper(input);
	}
	
	// RETURNS PROPER BOOLIAN
	if (input == 'Y') {
		return true;
	}
	else {
		return false;
	}
}