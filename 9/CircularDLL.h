#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Node;
class CircularDLL;

class Node
{
		friend class CircularDLL;
	private:
		int stId;
		string stName;
		string stEmail;
		int stAge;
		Node *next;
		Node *prev;
	public:
		Node() { next = this; prev = this; };
};

class CircularDLL
{
	private:
		void destroy(Node*&);

	public:
		Node *top;
		CircularDLL();
		CircularDLL(const CircularDLL& source);
		~CircularDLL();

		void insertDataFromFile(const string& filename);
		void print() const;
		bool search(int) const;
		void insertAfterFirst(int id, const string& name, const string& email, int age);
		void insertBeforeFirst(int id, const string& name, const string& email, int age);
		void insertAfterLast(int id, const string& name, const string& email, int age);
		void insertBeforeLast(int id, const string& name, const string& email, int age);
		void remove(int);
		void copy(Node* top1, Node*& top2);
};
