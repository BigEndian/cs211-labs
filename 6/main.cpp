#include "Professor.h"
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
	AdjunctProf ASmith;
	ASmith.setName( string( "Adam Smith" ) );
	ASmith.setFacultyId(12345L);
	ASmith.setEmail( string( "asmith@csusm.edu" ) );
	ASmith.setDegree('M');
	ASmith.setNoOfCourses(1);
	ASmith.setNoOfTA(2);
	cout << ASmith.getName() << "'s salary is " << ASmith.findSalary() << endl;
	ASmith.print();

	TenureTrackProf JAnderson;
	JAnderson.setName( string( "Jim Anderson" ) );
	JAnderson.setFacultyId(54321L);
	JAnderson.setEmail( string( "janderson@csusm.edu" ) );
	JAnderson.setRank('S');
	JAnderson.setYearOfExp(8);
	cout << JAnderson.getName() << "'s salary is " << JAnderson.findSalary() << endl;
	JAnderson.print();
	return 0;
}
