#include "Person.h"

Person::Person()
{
	this->SSN = -1L;
	this->Fname = ""; // For clarity
	this->Lname = ""; // For clarity
	this->Age = -1;
	this->Gender = '\0';
}
Person::Person(long SSN, string& Fname, string& Lname, int Age, char Gender)
{
	this->SSN = SSN;
	this->Fname = Fname;
	this->Lname = Lname;
	this->Age = Age;
	this->Gender = Gender; // Assume validity
}
void Person::SetAPerson(long SSN, string& Fname, string& Lname, int Age, char Gender)
{
	this->SSN = SSN;
	this->Fname = Fname;
	this->Lname = Lname;
	this->Age = Age;
	this->Gender = Gender; // Assume validity
}
void Person::PrintAPerson()
{
	cout << "Person " <<  this->Fname << " " << this->Lname << " (SSN " << this->SSN << ") age " << this->Age << " gender " << this->Gender;
}
