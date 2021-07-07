#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "Bank.h"
using namespace std;


int MenuInput();

void PrintCustomersData(const vector<int> id, const vector<string> first, const vector<string> last, const vector<double> savings_account, const vector<double> checking_account, int size);

void PrintNames(const vector<int> id, const vector<string> first, const vector<string> last, int size);

void PrintTotal(const vector<int> id, const vector<double> savings_account, const vector<double> checking_account, int size);