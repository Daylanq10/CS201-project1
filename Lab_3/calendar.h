#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include "calendar.h"


int GetYear();

int GetStartDayNumber();

int DaysPerMonth(int MonthNumber, int Year);

void PrintOneMonth(int MonthNumber, int Year, int& StartDayNumber);