#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;


int main(int argc, char *argv[])
{
	Employee emp1;
	emp1.Print();
	Employee emp2("unknown", 10, '?', 0); // name, department number, position, years of experience
	emp2.GetInfo();
	cout << endl; // Make the output cleaner
	SetSalary(emp2);
	emp2.Print();
	return 0;
}
