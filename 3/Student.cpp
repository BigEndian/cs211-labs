#include "Student.h"
#include "Course.h"

Student::Student()
{
	this->StNo = -1L;
}

Student::Student(long StNo, Course& Course1, Course& Course2, Course& Course3)
{
	this->StNo = StNo;
	this->Course1 = Course1;
	this->Course2 = Course2;
	this->Course3 = Course3;
}
void Student::SetAStudent(long StNo, Course& Course1, Course& Course2, Course& Course3)
{
	this->StNo = StNo;
	this->Course1 = Course1;
	this->Course2 = Course2;
	this->Course3 = Course3;
}
void Student::PrintAStudent()
{
	cout << "Student ID " << StNo << endl;
	Course1.PrintACourse();
	Course2.PrintACourse();
	Course3.PrintACourse();

}
