#include <iostream>
#include "Employee.h"
#include "string"
#include <fstream>
using namespace std;

//ALL AS THEY SOUND SO I WONT REPEAT THE NAME OF ALL THE FUNCTIONS WITH A DESCRIPTION

string Employee::getname() const
{
	return name;
}

string Employee::getid() const
{
	return id;
}

void Employee::setname(const string & newname)
{
	name = newname;
}

void Employee::setid(const string & newid)
{
	id = newid;
}

string Employee::gettype() const
{
	return "Employee";
}

bool Employee::readdata(istream & in) 
{
	if (in.good()) {

		string newname;
		string newid;
		getline(in, newname);
		name = newname;
		getline(in, newid);
		id = newid;
		return true;
	}
	else {
		return false;
	}
}

bool Employee::writedata(ostream & out) const 
{
	if (out.good()) {
		out << name << endl;
		out << id << endl;
		return true;
	}
	else { return false; };
}


HourlyEmployee::HourlyEmployee()
{
	setname("0");
	setid("0");
	experience = 'n';
	salary = 0;
}

char HourlyEmployee::getexpertemployee() const
{
	return experience;
}

double HourlyEmployee::getsalary() const  
{
	return salary;
}

string HourlyEmployee::gettype() const
{
	return "Hourly Employee";
}

bool HourlyEmployee::setexpertemployee(char newexpert)
{
	return newexpert;
}

bool HourlyEmployee::setsalary(double newsalary)
{
	if (newsalary >= 1000 && newsalary <= 10000) {
		salary = newsalary;
		return true;
	}
	else {
		return false;
	}
}

bool HourlyEmployee::readdata(istream & in)
{
	if (in.good()) {
		Employee::readdata(in);
		char exp;
		double sal;
		in >> exp;
		experience = exp;
		in >> sal;
		salary = sal;
		return true;
	}
	else { return false; };
}

bool HourlyEmployee::writedata(ostream & out) const
{
	if (out.good()) {
		out << gettype() << endl;
		Employee::writedata(out);
		out << experience << endl;
		out << salary << endl;
		return true;
	}
	else { return false; };
}

MonthlyEmployee::MonthlyEmployee()
{
	setname("0");
	setid("0");
	rank = 0;

}

bool MonthlyEmployee::setrank(int newrank)
{
	if (newrank >= 1 && newrank <= 10) {
		rank = newrank;
		return true;
	}
	else { return false; };
}

string MonthlyEmployee::gettype() const
{
	return "Monthly Employee";
}

bool MonthlyEmployee::readdata(istream & in)
{
	if (in.good()) {
		
		Employee::readdata(in);
		int ranking;
		in >> ranking;
		rank = ranking;

		return true;
	}
	else { return false; };
}

bool MonthlyEmployee::writedata(ostream & out) const
{
	if (out.good()) {
		out << gettype() << endl;
		Employee::writedata(out);
		out << rank << endl;
		return true;
	}
	else { return false; };
}
