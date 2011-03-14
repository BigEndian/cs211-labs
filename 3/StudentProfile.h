#pragma once
#include "Student.h"
#include "Person.h"
#include "Course.h"
#include <iostream>

class StudentProfile
{
	private:
		Person PersonalInfo;
		Student StdInfo;
	public:
		StudentProfile() {} ;
		StudentProfile(Person&, Student&);
		void SetAStudentProfile(Person&, Student&);
		void PrintAStudentProfile();
};
