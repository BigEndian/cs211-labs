#include "Course.h"
#include <iostream>

using namespace std;

Course::Course()
{
	this->courseNum = -1L;
	// courseName is already initialized to an empty string
}
Course::Course(long courseNum, string courseName)
{
	this->courseNum = courseNum;
	this->courseName = courseName;
}
void Course::SetACourse(long courseNum, string courseName)
{
	this->courseNum = courseNum;
	this->courseName = courseName;
}
void Course::PrintACourse()
{
	cout << "Course \"" << this->courseName << "\" ( ID " << this->courseNum << " )" << endl;
}
