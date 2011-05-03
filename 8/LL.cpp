#include "LL.h"
#include <string>
#include <iostream>
#include <fstream>


using namespace std;
LL::LL()
{
	top = NULL;
}
LL::LL(const LL& source)
{
	top = NULL; 
	copy(source.top, top);
}
LL::~LL()
{
	destroy(this->top);
}
void LL::destroy(Node*& startingPoint)
{
	if (startingPoint == NULL)
	{
		return;
	}
	Node *priorNode;
	while (startingPoint != NULL)
	{
		priorNode = startingPoint;
		startingPoint = startingPoint->next;
		delete priorNode;
	}

	// At the end, startingPoint, the PASSED pointer, should be NULL.
	// so if you pass top, top will be NULL at the end.

}
void LL::insertDataFromFile(const string& filename)
{
	ifstream dataIfs(filename.c_str());

	if (!dataIfs)
	{
		cerr << "File \"" << filename << "\" could not be opened" << endl;
		return;
	}

	int stId;
	string stName, stEmail;
	int stAge;

	while (dataIfs >> stId >> stName >> stEmail >> stAge)
	{
		this->insertAfterLast(stId, stName, stEmail, stAge);
	}

	dataIfs.close();

}
void LL::print()
{
	if (top == NULL)
	{
		cout << "List is empty." << endl;
	}

	Node *currentNode = top;

	while (currentNode != NULL)
	{
		cout << "Node (addr " << ((int*)currentNode) << "): " << currentNode->stName << " <" <<
						currentNode->stEmail << "> age " << currentNode->stAge << ", ID " << currentNode->stId << ")" << endl;
		/*cout << "Node (addr " << ((int*)currentNode) << "):" << endl <<
			"\tstId:    " << currentNode->stId << endl <<
			"\tstName:  " << currentNode->stName << endl <<
			"\tstEmail: " << currentNode->stEmail << endl <<
			"\tstAge:   " << currentNode->stAge << endl;*/
		currentNode = currentNode->next;
	}

}
bool LL::search(int id)
{
	if (top == NULL)
	{
		return false;
	}

	Node *tmp = top;

	while (tmp != NULL)
	{
		if (tmp->stId == id)
			return true;
		tmp = tmp->next;
	}

	return false;
}
void LL::insertAfterFirst(int id, const string& name, const string& email, int age)
{
	Node *newNode = new Node;
	newNode->stId    = id;
	newNode->stName  = name;
	newNode->stEmail = email;
	newNode->stAge   = age;

	if (top == NULL) // 0 Nodes
	{
		top = newNode;
		return;
	}

	Node *nodeAfterNewNode = top->next;
	newNode->next = nodeAfterNewNode;
	top->next = newNode;

}
void LL::insertBeforeFirst(int id, const string& name, const string& email, int age)
{
	Node *newNode = new Node;
	newNode->stId    = id;
	newNode->stName  = name;
	newNode->stEmail = email;
	newNode->stAge   = age;

	if (top == NULL) // 0 nodes
	{
		top = newNode;
		return;
	}

	Node *oldTop = top;
	top = newNode;
	top->next = oldTop;
}
void LL::insertAfterLast(int id, const string& name, const string& email, int age)
{
	Node *newNode = new Node;
	newNode->stId    = id;
	newNode->stName  = name;
	newNode->stEmail = email;
	newNode->stAge   = age;

	if (top == NULL)
	{
		top = newNode;
		return;
	}


	Node *lastNode = top;
	while (lastNode->next != NULL) // Iterate to the last node
	{
		lastNode = lastNode->next;
	}

	lastNode->next = newNode; // Set the last node's next pointer to point to this new node.
}
void LL::insertBeforeLast(int id, const string& name, const string& email, int age)
{ 
	Node *newNode = new Node;
	newNode->stId    = id;
	newNode->stName  = name;
	newNode->stEmail = email;
	newNode->stAge   = age;

	if (top == NULL) // Talk about boilerplate code..
	{
		top = newNode;
		return;
	}

	if (top->next == NULL) // One node
	{
		Node *oldTop = top;
		top = newNode;
		top->next = oldTop;
	}

	Node *secondToLastNode = top, *lastNode = top;

	while (lastNode->next != NULL)
	{
		secondToLastNode = lastNode;
		lastNode = lastNode->next;
	}

	newNode->next = lastNode;         // Have the new node's next point to the last node
	secondToLastNode->next = newNode; // and have what will no longer be the second-to-last node point to the new node.
}
void LL::remove(int id)
{
	if (top == NULL)
	{
		return;
	}


	Node *priorNode = NULL, *nodeToDelete = top;

	while (nodeToDelete != NULL && nodeToDelete->stId != id)
	{
		priorNode = nodeToDelete;
		nodeToDelete = nodeToDelete->next;
	}

	if (priorNode == NULL) // The first node matched
	{
		top = top->next; // Top will now be the node AFTER top.
	}
	else // A different node matched
	{
		priorNode->next = nodeToDelete->next; // The one before's next will point to the node after nodeToDelete.
	}
	delete nodeToDelete; // Finally, delete. No references to the node wille exist anymore.
}
void LL::copy(Node* top1, Node*& top2)
{
	destroy(top2);

	Node *lcurr, *rcurr;

	if (top1 != NULL) // If the source list isn't empty
	{
		top2 = new Node; // Create the first node on the right.

		top2->stId = top1->stId;
		top2->stName = top1->stName;
		top2->stEmail = top1->stEmail;
		top2->stAge = top1->stAge;

		rcurr = top2;
		lcurr = top1;

		while (lcurr->next != NULL) // Use next, as top has already been accounted for
		{
			rcurr->next = new Node; // create the next node ...
			rcurr = rcurr->next; // Then move to it
			lcurr = lcurr->next; // Same for the source node

			rcurr->stId = lcurr->stId;
			rcurr->stName = lcurr->stName;
			rcurr->stEmail = lcurr->stEmail;
			rcurr->stAge = lcurr->stAge;
		}
		// We're done copying, so set next on the last node of the fresh list to null
		rcurr->next = NULL;
	}
}
