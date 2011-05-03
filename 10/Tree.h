#include <iostream>
#include <string>

using namespace std;

class TreeStruct
{
	public:
		int number;
		TreeStruct* left;
		TreeStruct* right;
		TreeStruct() { left = NULL; right = NULL; };

};

class Tree
{
	public:
		Tree();
		~Tree();

		TreeStruct* root;

		void Destroy(TreeStruct*& Root);
		void InsertIntoTree(TreeStruct*& Root, int number);
		int  FindMaxLen(TreeStruct* Root); 
		int  FindMinLen(TreeStruct* Root); 
		int  CountNodes(TreeStruct* Root);
		void Copy(TreeStruct* Root1, TreeStruct*& Root2); //copies one tree into another
		bool Search(TreeStruct* Root, int n);
		void PrintInOrderTree(TreeStruct* Root);
		void PrintPreOrderTree(TreeStruct* Root);
		void PrintPostOrderTree(TreeStruct* Root);

};
