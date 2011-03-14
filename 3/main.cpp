#include <fstream>
#include <string>
#include "StudentCollection.h"

using namespace std;

int main()
{
	StudentCollection sc;
	sc.GetInfo("data.txt");
	sc.PrintAStudentCollection();
	return 0;
}

