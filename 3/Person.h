#pragma once
#include <iostream>

using namespace std;

class Person
{
	private:
		long SSN;
		string Fname;
		string Lname;
		int Age;
		char Gender;
	public:
		Person();
		Person(long, string&, string&, int, char);
		void SetAPerson(long, string&, string&, int, char);
		void PrintAPerson();
};
