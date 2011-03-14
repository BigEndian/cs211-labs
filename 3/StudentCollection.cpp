#include "StudentCollection.h"
#include "StudentProfile.h"
#include "Person.h"
#include "Student.h"
#include "Course.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;


void StudentCollection::SetAStudentCollection(StudentProfile& SP)
{
	this->StCollection.erase( this->StCollection.begin(), this->StCollection.end() );
	this->StCollection.push_back(SP);
}
void StudentCollection::SetAStudentCollection(vector<StudentProfile>& StCollection)
{
	this->StCollection = StCollection;
}

void StudentCollection::PrintAStudentCollection()
{
	for (unsigned int i = 0; i < this->StCollection.size(); i++)
	{
		cout << "Student Profile " << i << ": " << endl;
		this->StCollection[i].PrintAStudentProfile();
	}
}
void StudentCollection::GetInfo(const string& filename)
{
	string type;
	Course courses[3];
	Student students[3];
	Person people[3];
	StudentProfile profiles[3];
	ifstream fin(filename.c_str());
	if (!fin)
		return;
	
	// Course stuff
	int courseID;
	string courseName;
	
	// Person stuff
	string personFname, personLname;
	long personSSN;
	unsigned int personAge;
	char personGender;
	
	// Student stuff
	long studentNumber;
	// Courses are all the same.
	// I'm not coding in much flexibility on purpose.
	
	unsigned int personCounter = 0,
		studentCounter = 0,
		courseCounter = 0;
	
	while (fin >> type) 
	{
		if (type == "Person" && personCounter < 3)
		{
			fin >> personFname >> personLname >> personSSN >> personAge >> personGender; // Read the data
			people[personCounter++].SetAPerson(personSSN, personFname, personLname, personAge, personGender); // Set the person using the data
		}
		else if (type == "Student" && studentCounter < 3)
		{
			fin >> studentNumber;
			students[studentCounter++].SetAStudent(studentNumber, courses[0], courses[1], courses[2]);
			// Those courses could just be default if they're never specified in the file, but oh well.
		}
		else if (type == "Course" && courseCounter < 3)
		{
			fin >> courseID;
			fin.ignore(); // Skip the space
			//fin.getline(courseNameBuffer, 128);
			getline(fin, courseName);
			courses[courseCounter++].SetACourse(courseID, courseName);
			courseName = "";
		}
	}
	fin.close();
	for (int i = 0; i < 3; i++)
	{
		students[i].SetCourse(courses[0], 0);
		students[i].SetCourse(courses[1], 1);
		students[i].SetCourse(courses[2], 2);
		profiles[i].SetAStudentProfile(people[i], students[i]); // Set a student profile
		this->StCollection.push_back(profiles[i]); // Add the student profile
	}
}
