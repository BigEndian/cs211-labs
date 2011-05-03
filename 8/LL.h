#pragma once
#include <string>
#include <iostream>
#include <fstream>

#ifndef NULL
#define NULL 0
#endif

using namespace std;


class Node;
class LL;

class Node
{
	public:
		friend class LL;
		Node() { next = NULL; };
	private:
		int stId;
		string stName;
		string stEmail;
		int stAge;
		Node* next;
};

class LL
{
	private:
		void destroy(Node*&);
	public:
		Node *top;
		LL();
		LL(const LL& source); // Copy constructor
		~LL();
		void insertDataFromFile(const string& filename);
		void print();
		bool search(int);

		void insertAfterFirst  ( int id, const string& name, const string& email, int age);
		void insertBeforeFirst ( int id, const string& name, const string& email, int age);
		void insertAfterLast   ( int id, const string& name, const string& email, int age);
		void insertBeforeLast  ( int id, const string& name, const string& email, int age);
		void remove(int);
		void copy(Node* top1, Node*& top2);
};
