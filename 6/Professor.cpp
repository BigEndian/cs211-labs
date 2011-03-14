#include "Professor.h"
#include <string>
#include <iostream>

using namespace std;

CompSciProfessor::CompSciProfessor()
{
	this->facultyId = 0;
}
CompSciProfessor::CompSciProfessor(string name, string email, long facultyId)
{
	this->name = name;
	this->email = email;
	this->facultyId = facultyId;
}

void CompSciProfessor::setName(const string& name)
{
	this->name = name;
}
void CompSciProfessor::setEmail(const string& email)
{
	this->email = email;
}
void CompSciProfessor::setFacultyId(long facultyId)
{
	this->facultyId = facultyId;
}
string CompSciProfessor::getName() const
{
	return this->name;
}
string CompSciProfessor::getEmail() const
{
	return this->email;
}
long CompSciProfessor::getFacultyId() const
{
	return this->facultyId;
}
// Adjunct Professor stuff
AdjunctProf::AdjunctProf()
{
	this->facultyId = 0;
	this->degree = 'B';
	this->noOfTA = 0;
	this->noOfCourses = 0;
}
AdjunctProf::AdjunctProf(const string& name, const string& email, long facultyId, char degree, int noOfTA, int noOfCourses)
{
	this->name = name;
	this->email = email;
	this->facultyId = facultyId;
	this->degree = degree;
	this->noOfTA = noOfTA;
	this->noOfCourses = noOfCourses;
}
void AdjunctProf::setDegree(char degree)
{
	this->degree = degree;
}
void AdjunctProf::setNoOfTA(int noOfTA)
{
	this->noOfTA = noOfTA;
}
void AdjunctProf::setNoOfCourses(int noOfCourses)
{
	this->noOfCourses = noOfCourses;	
}
void AdjunctProf::print() const
{
	cout << "Professor name: " << this->name << endl;
	cout << "Professor email: " << this->email << endl;
	cout << "Professor facID: " << this->facultyId << endl;
	cout << "Professor degree: '" << this->degree << '\'' << endl;
	cout << "Professor # of TAs: " << this->noOfTA << endl;
	cout << "Professor # of Courses: " << this->noOfCourses << endl;
}
float AdjunctProf::findSalary() const
{
	float amtPerTA, amtPerCourse;
	if (this->degree == 'B')
	{
		amtPerTA = 1500.0f;
		amtPerCourse = 2000.0f;
	}
	else if (this->degree == 'M')
	{
		amtPerTA = 2000.0f;
		amtPerCourse = 4000.0f;
	}
	else if (this->degree == 'P')
	{
		amtPerTA = 2500.0f;
		amtPerCourse = 5000.0f;
	}
	return ( this->noOfTA * amtPerTA ) + ( this->noOfCourses * amtPerCourse );
}

// TenureTracKProf
TenureTrackProf::TenureTrackProf()
{
	this->facultyId = 0;
	this->rank = 'A';
	this->yearOfExp = 0;
}
TenureTrackProf::TenureTrackProf(const string& email, const string& name, long facultyId, char rank, int yearOfExp)
{
	this->email = email;
	this->name = name;
	this->facultyId = facultyId;
	this->rank = rank;
	this->yearOfExp = yearOfExp;
}
void TenureTrackProf::setRank(char rank)
{
	this->rank = rank;
}
void TenureTrackProf::setYearOfExp(int yearOfExp)
{
	this->yearOfExp = yearOfExp;
}
char TenureTrackProf::getRank() const
{
	return this->rank;
}
int TenureTrackProf::getYearOfExp() const
{
	return this->yearOfExp;
}
float TenureTrackProf::findSalary() const
{
	if (this->rank == 'A') // Assistant
		return (65000.0f) + (1500.0f * this->yearOfExp);
	else if (this->rank == 'S') //Associatate
		return (80000.0f) + (1500.0f * this->yearOfExp);
	else // Whatever the last one is, although this WILL match invalid ranks.
		return (90000.0f) + (1500.0f * this->yearOfExp);
}
void TenureTrackProf::print() const
{
	cout << "Professor name: " << this->name << endl;
	cout << "Professor email: " << this->email << endl;
	cout << "Professor facID: " << this->facultyId << endl;
	cout << "Professor rank: '" << this->rank << '\'' << endl;
	cout << "Professor years of experience: " << this->yearOfExp << endl;
}

