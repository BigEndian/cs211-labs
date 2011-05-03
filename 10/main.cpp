#include "Tree.h"

int main(int argc, char *argv[])
{
	Tree t;
	t.InsertIntoTree(t.root, 15);
	t.InsertIntoTree(t.root, 20);
	t.InsertIntoTree(t.root, 10);
	t.InsertIntoTree(t.root, 8);
	t.InsertIntoTree(t.root, 9);
	t.InsertIntoTree(t.root, 17);
	t.InsertIntoTree(t.root, 21);
	t.InsertIntoTree(t.root, 22);
	t.InsertIntoTree(t.root, 23);
	t.InsertIntoTree(t.root, 24);
	t.InsertIntoTree(t.root, 25);
	t.InsertIntoTree(t.root, 26);
	t.InsertIntoTree(t.root, 11);

	cout << "\nPrinting Pre Order " << endl;
	t.PrintPreOrderTree(t.root);
	cout << "\n-----------------------------------------------" << endl;

	cout << "Printing Post Order " << endl;
	t.PrintPostOrderTree(t.root);
	cout << "\n-----------------------------------------------" << endl;

	cout << "Printing In Order " << endl;
	t.PrintInOrderTree(t.root);
	cout << "\n-----------------------------------------------" << endl;

	cout << boolalpha << endl << endl;
	cout << "\nSearching 30: " << t.Search(t.root, 30) << endl;
	cout << "\nSearching 8: " << t.Search(t.root, 8) << endl;
	cout << "\nSearching 10: " << t.Search(t.root, 10) << endl;
	cout << "-------------------------------------------" << endl;

	int MaxLen = t.FindMaxLen(t.root);
	int MinLen = t.FindMinLen(t.root);
	int TotalNodes = t.CountNodes(t.root);

	cout << "Max is " << MaxLen << endl;
	cout << "Min is " << MinLen << endl;
	cout << "Num of Nodes is " << TotalNodes << endl;
	cout << "-----------------------------------------------" << endl;

	Tree t2;
	t.Copy( t.root, t2.root);
	cout << "Printing In Order the copy of the tree" << endl;
	t2.PrintInOrderTree(t2.root);
	cout << "\n-----------------------------------------------" << endl;

	return 0;
}
