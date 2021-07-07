#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Student {

private:
	string firstname;
	string lastname;
	int ID;
	int itemnum;
	string* size;
	vector<string> items;

public:
	Student(string, string, int, int, vector<string>);
	string get_firstname();
	string get_lastname();
	int get_ID();
	int get_itemnum();
	string get_items(int);
	void AddItem(string item_add);
	void IncItems();
	void DecItems();
	void RemoveItem(int);
	void print();
};

vector<Student> Student_Members();

vector<Student> Members_Checkouts(vector<Student> Members);

vector<Student> Members_End(vector<Student> Members);

void Output_file(vector<Student> Members);