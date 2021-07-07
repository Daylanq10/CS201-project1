#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "RecCenter.h"
using namespace std;


Student::Student(string name1, string name2, int IDnum, int itemnum1, vector<string> items1) {

	firstname = name1;
	lastname = name2;
	ID = IDnum;
	itemnum = itemnum1;
	items = items1;
}

string Student::get_firstname() {
	return firstname;
}

string Student::get_lastname() {
	return lastname;
}

int Student::get_ID() {
	return ID;
}

int Student::get_itemnum() {
	return itemnum;
}

//USED TO ITERATE THROUGH VECTOR OF STUDENTS ITEMS
string Student::get_items(int index) {
	return items[index];
}

//REMOVES ITEM FROM STUDENTS CURRENT ITEMS IF CHECKED IN
void Student::RemoveItem(int index) {
	items.erase(items.begin() + index);
}

//ADDS CHECKED OUT ITEM TO STUDENTS CURRENT ITEMS
void Student::AddItem(string item_add) {
	items.push_back(item_add);
}

//INCRIMENT ITEMNUM WHEN ITEM IS CHECKED OUT
void Student::IncItems() {
	itemnum += 1;
}

//DECRIMENT ITEMNUM WHEN ITEM IS CHECKED IN
void Student::DecItems() {
	itemnum -= 1;
}

//NOT NECESSARY BUT IM LEAVING IT BECAUSE THIS IS HOW I CHECKED EVERYTHING
void Student::print() {
	cout << firstname << " " << lastname << " " << ID << " " << itemnum << endl;
	for (int i = 0; i < itemnum; ++i) { // ADDED ONE TO ACCOUNT FOR BEGINNING BLANK
		cout << items[i + 1] << endl;
	}
	cout << endl;
}


//CREATES MY FIRST ITERATION OF INITIAL STUDENTS WITH INFO
vector<Student> Student_Members() {

	vector<Student> student_members;

	ifstream ifile("Students.txt");
	if (ifile) {
		int temp_id;
		int temp_items;
		string temp_name1;
		string temp_name2;
		while (!ifile.eof()) {
			ifile >> temp_id;
			ifile >> temp_name1;
			ifile >> temp_name2;
			ifile >> temp_items;

			if (temp_items > 0) {
				string item;
				string push = " ";
				vector<string> temp_items_vector;
				temp_items_vector.push_back(push);
				for (int i = 0; i < temp_items; ++i) {
					ifile >> item;
					temp_items_vector.push_back(item);
				}
				Student temp_student(temp_name1, temp_name2, temp_id, temp_items, temp_items_vector);
				student_members.push_back(temp_student);
			}
			else {
				string push = " ";
				vector<string> temp_items_vector;
				temp_items_vector.push_back(push);
				Student temp_student(temp_name1, temp_name2, temp_id, temp_items, temp_items_vector);
				student_members.push_back(temp_student);
			}
		}
	}
	ifile.close();
	return student_members;
}


//CREATES SECOND ITERATION OF STUDENTS AFTER CHECKOUTS
vector<Student> Members_Checkouts(vector<Student> Members) {
	//adds iphone twice at end for some reason
	ifstream infile("checkouts.txt");
	if (infile) {
		int temp_id;
		string temp_item;
		while (!infile.eof()) {
			infile >> temp_id;
			infile >> temp_item;
			for (int i = 0; i < Members.size(); ++i) {
				if (temp_item != ""){
					if (Members[i].get_ID() == temp_id) {
						Members[i].AddItem(temp_item);
						Members[i].IncItems();
						temp_id = 0;
						temp_item = "";
					}
				}
			}
		}
	}
	infile.close();
	return Members;
}


//CREATES LAST ITERATION OF STUDENT WITH CHECKINS APPLIED
vector<Student> Members_End(vector<Student> Members) {
	ifstream infile("checkins.txt");
	if (infile) {
		string temp_item;
		while (!infile.eof()) {
			infile >> temp_item;
			for (int i = 0; i < Members.size(); ++i) {
				for (int j = 0; j < Members[i].get_itemnum(); ++j) {

					if (temp_item == Members[i].get_items(j)) {
						cout << temp_item;
						Members[i].DecItems();
						Members[i].RemoveItem(j);
						temp_item = "N/A";	//Not professional but it works kinda
					}
				}
			}
		}
	}
	infile.close();
	return Members;
}


//CREATES OUTPUT FILE WITH UPDATED STUDENT VECTOR INFORMATION
void Output_file(vector<Student> Members) {

	ofstream fout("Updated_Students.txt");

	for (int i = 0; i < Members.size(); ++i) {
		fout << Members[i].get_ID() << "\t" << Members[i].get_firstname() << "\t" << Members[i].get_lastname() << endl;
		fout << Members[i].get_itemnum() << " ";
		for (int j = 0; j <= Members[i].get_itemnum(); ++j) {
			fout << Members[i].get_items(j) << endl;
		}
		fout << endl;
	}
	fout.close();
}