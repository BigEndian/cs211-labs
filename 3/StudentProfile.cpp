#include "StudentProfile.h"
#include "Student.h"
#include "Person.h"
#include "Course.h"
#include <iostream>

using namespace std;

StudentProfile::StudentProfile(Person& PersonalInfo, Student& StdInfo)
{
	this->PersonalInfo = PersonalInfo;
	this->StdInfo = StdInfo;
}
void StudentProfile::SetAStudentProfile(Person& PersonalInfo, Student& StdInfo)
{
	this->PersonalInfo = PersonalInfo;
	this->StdInfo = StdInfo;
}
void StudentProfile::PrintAStudentProfile()
{
	//cout << this->PersonalInfo << endl << this->StdInfo;
	this->PersonalInfo.PrintAPerson();
	cout << endl;
	this->StdInfo.PrintAStudent();
}
