#pragma once
#include "StudentProfile.h"
#include "Person.h"
#include "Student.h"
#include "Course.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class StudentCollection
{
	private:
		vector<StudentProfile> StCollection;
	public:
		StudentCollection() {} ; // Pointless
		void SetAStudentCollection(StudentProfile&);
		void SetAStudentCollection(vector<StudentProfile>&);
		void PrintAStudentCollection();
		void GetInfo(const string& filename);
};
