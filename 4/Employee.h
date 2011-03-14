#pragma once
#include <string>
#include <iostream>

using namespace std;


class Employee
{
	private:
		string name;
		const long officeNo;
		const long empId;
		int deptNo;
		char empPosition; // 'E': entry level, 'M': manager, 'D': Director, 'P': Project_leader
		int yearOfExp;
		double salary;
		static int totalNumOfEmployees;// = 0;
		static int nextEmpId;// = 1000;
		static int nextOfficeNo;//=10;
	public:
		/*Employee() : officeNo( nextOfficeNo++ ), empId( nextEmpId++ ), name("Unknown"),
			deptNo(0), empPosition('E'), yearOfExp(0), salary(0.0) { totalNumOfEmployees++; };*/
		Employee() : officeNo(nextOfficeNo++), empId(nextEmpId++)
		{
			name = "Unknown";
			deptNo = 0;
			empPosition = 'E';
			yearOfExp = 0;
			salary = 0.0;
			totalNumOfEmployees++;
		}
		~Employee() { totalNumOfEmployees--; };
		/*Employee(string Name, int DeptNo, char EmpPosition, int YearOfExp) : officeNo(nextOfficeNo++), empId(nextEmpId++),
			name(Name), deptNo(DeptNo), empPosition(EmpPosition), yearOfExp(YearOfExp), salary(0.0) { totalNumOfEmployees++; };*/
		Employee(const string& name, int deptNo, char empPosition, int yearOfExp) : officeNo(nextOfficeNo++), empId(nextEmpId++)
		{
			this->name        = name;
			this->deptNo      = deptNo;
			this->empPosition = empPosition;
			this->yearOfExp   = yearOfExp;
			this->salary      = 0.0;
			totalNumOfEmployees++;
		}

		void Print() const;
		void GetInfo();
		friend void SetSalary(Employee&);
};

