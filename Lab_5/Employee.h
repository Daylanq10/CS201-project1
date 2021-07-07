#pragma once
#include <iostream>
using namespace std;

//BASE CLASS
class Employee {

	string name;
	string id;

public:
	string getname() const;
	string getid() const;
	void setname(const string& newname);
	void setid(const string& newid);
	virtual string gettype() const;
	virtual bool readdata(istream&);
	virtual bool writedata(ostream&) const;   //pure virtual 
};

// DERIVED CLASS
class HourlyEmployee : public Employee {
	char experience;
	double salary;

public:
	HourlyEmployee();
	char getexpertemployee() const; //not too positive on this one
	double getsalary() const;
	virtual string gettype() const;
	bool setexpertemployee(char newexpert);
	bool setsalary(double newsalary);
	virtual bool readdata(istream& in);
	virtual bool writedata(ostream& out) const;
};

//DERIVED CLASS
class MonthlyEmployee : public Employee {

	int rank;

public:
	MonthlyEmployee();
	bool setrank(int);
	virtual string gettype() const;
	virtual bool readdata(istream& in);
	virtual bool writedata(ostream& out) const;

};