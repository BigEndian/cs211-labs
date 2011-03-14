#pragma once
#include <string>
#include <iostream>

using namespace std;

class CompSciProfessor
{
protected:
	string name;
	string email;
	long facultyId;
public:
	CompSciProfessor();
	CompSciProfessor(string, string, long);
	void setName(const string& name);
	void setEmail(const string& email);
	void setFacultyId(long facultyId);	

	string getName() const;
	string getEmail() const;
	long getFacultyId() const;
};

class AdjunctProf : public CompSciProfessor
{
private:
	char degree;
	int noOfTA;
	int noOfCourses;
public:
	AdjunctProf();
	AdjunctProf(const string& name, const string& email, long facultyId, char degree, int noOfTA, int noOfCourses);

	void setDegree(char degree);
	void setNoOfTA(int noOfTA);
	void setNoOfCourses(int noOfCourses);

	char getDegree()   const ;
	int getNoOfTA()    const ;

	void print()       const ;
	float findSalary() const ;
};

class TenureTrackProf : public CompSciProfessor
{
private:
	char rank;
	int yearOfExp;
public:
	TenureTrackProf();
	TenureTrackProf(const string& name, const string& email, long facultyId, char rank, int yearOfExp);
	void setRank(char rank);
	void setYearOfExp(int yearOfExp);
	char getRank() const;
	int  getYearOfExp() const;
	float findSalary() const;
	void print() const;
};
