#include "Tree.h"

Tree::Tree()
{
	root = NULL;
}
Tree::~Tree()
{
	Destroy(root);
}
void Tree::Destroy(TreeStruct*& Root)
{
	if (Root != NULL)
	{
		Destroy(Root->left);
		Destroy(Root->right);
		delete Root;
		Root = NULL;
	}
}
void Tree::InsertIntoTree(TreeStruct*& Root, int number)
{
	if (Root == NULL)
	{
		Root = new TreeStruct;
		Root->number = number;
	}
	else if (number < Root->number)
	{
		InsertIntoTree(Root->left, number);
	}
	else if (number > Root->number)
	{
		InsertIntoTree(Root->right, number);
	}
}
int Tree::CountNodes(TreeStruct* Root)
{
	if (Root == NULL)
		return 0;
	
	int leftCount  = CountNodes(Root->left);
	int rightCount = CountNodes(Root->right);

	return 1 + leftCount + rightCount;
}
int Tree::FindMaxLen(TreeStruct* Root)
{
	if (Root == NULL)
		return 0;

	int leftCount =  FindMaxLen(Root->left);
	int rightCount = FindMaxLen(Root->right);

	return (leftCount > rightCount) ? 1 + leftCount : 1 + rightCount;
}
int Tree::FindMinLen(TreeStruct* Root)
{
	if (Root == NULL)
		return 0;

	int leftCount =  FindMinLen(Root->left);
	int rightCount = FindMinLen(Root->right);

	return (leftCount < rightCount) ? 1 + leftCount : 1 + rightCount;
}
bool Tree::Search(TreeStruct* Root, int n)
{
	if (Root == NULL)
		return false;
	
	if (Root->number == n)
		return true;

	if (n < Root->number)
		return Search(Root->left, n);
	else
		return Search(Root->right, n);
}
void Tree::PrintInOrderTree(TreeStruct* Root)
{
	if (Root != NULL)
	{
		PrintInOrderTree(Root->left);
		cout << Root->number << "-->";
		PrintInOrderTree(Root->right);
	}
}
void Tree::PrintPostOrderTree(TreeStruct* Root)
{
	if (Root != NULL)
	{
		PrintPostOrderTree(Root->left);
		PrintPostOrderTree(Root->right);
		cout << Root->number << "-->";
	}
}
void Tree::PrintPreOrderTree(TreeStruct* Root)
{
	if (Root != NULL)
	{
		cout << Root->number << "-->";
		PrintPreOrderTree(Root->left);
		PrintPreOrderTree(Root->right);
	}
}
void Tree::Copy(TreeStruct* Root1, TreeStruct*& Root2)
{
	if (Root2 == NULL && Root1 != NULL)
	{
		Root2 = new TreeStruct;
		Root2->number = Root1->number;
		Copy(Root1->left, Root2->left);
		Copy(Root1->right, Root2->right);
	}
}
