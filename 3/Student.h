#pragma once
#include "Course.h"

class Student
{
	private:
		long StNo;
		Course Course1;
		Course Course2;
		Course Course3;
	public:
		Student();
		Student(long, Course&, Course&, Course&);
		void SetAStudent(long, Course&, Course&, Course&);
		void PrintAStudent();
};
