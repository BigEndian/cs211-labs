#include "CircularDLL.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	CircularDLL list1;
	list1.insertDataFromFile("data.txt");
	list1.print();
	cout << endl << endl;
	list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
	list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
	list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
	list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
	list1.print();
	cout << endl << endl;
	bool  found = list1.search (12321);
	if (found)
		cout << "the record was found" << endl;
	else
		cout << "the record was not found" << endl;
	list1.remove (54321);
	cout << endl << endl;
	list1.print();
	CircularDLL list2(list1);
	cout << endl << endl;
	list2.print();
	return 0;
}
