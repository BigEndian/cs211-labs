#include "LL.h"
#include <iostream>

using namespace std;

int main()
{
	LL list1;
	list1.insertDataFromFile("data.txt");
	// Mary Kathy Flora Peter Kim
	list1.print();
	cout << endl << endl; // Separator
	list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
	// Mary Jim Kathy Flora Peter Kim
	list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
	// Joe Mary Jim Kathy Flora Peter Kim
	list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
	// Joe Mary Jim Kathy Flora Peter Kim Adam
	list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
	// Joe Mary Jim Kathy Flora Peter Kim Nancy Adam
	list1.print();
	cout << endl << endl; // Separator
	bool  found = list1.search (12321);

	if (found)
		cout << "the record was found" << endl;
	else
		cout << "the record was not found" << endl;
	cout << endl << endl; // Separator
	list1.remove (54321);
	// Joe Mary Kathy Flora Peter Kim Nancy Adam
	list1.print();
	cout << endl << endl; // Separator
	LL list2(list1);
	list2.print();
	// Joe Mary Kathy Flora Peter Kim Nancy Adam

	return 0;
}
