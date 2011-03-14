#pragma once
#include <iostream>

using namespace std;
class Course 
{
	private:
		long courseNum;
		string courseName;
	public:
		Course();
		Course(long courseNum, string courseName);
		void SetACourse(long courseNum, string courseName);
		void PrintACourse();
};
