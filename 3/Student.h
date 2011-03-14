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
		void SetCourse(const Course& c, unsigned int index)
		{
			if (index == 0)
				Course1 = c;
			else if (index == 1)
				Course2 = c;
			else if (index == 2)
				Course3 = c;
		}
};
