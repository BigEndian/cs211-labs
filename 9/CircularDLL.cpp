#include "CircularDLL.h"

CircularDLL::CircularDLL()
{
	top = NULL;
}
CircularDLL::~CircularDLL()
{
	destroy(top);
}
CircularDLL::CircularDLL(const CircularDLL& source)
{
	top = NULL;
	copy(source.top, this->top);
}
void CircularDLL::copy(Node* leftTop, Node*& rightTop)
{
	destroy(rightTop);

	Node *lcurr, *rcurr;

	if (leftTop != NULL) // If the source list isn't empty
	{
		rightTop = new Node; // Create the first node on the right.

		rightTop->stId = leftTop->stId;
		rightTop->stName = leftTop->stName;
		rightTop->stEmail = leftTop->stEmail;
		rightTop->stAge = leftTop->stAge;

		rcurr = rightTop;
		lcurr = leftTop;

		while (lcurr->next != leftTop) // Use next, as top has already been accounted for
		{
			rcurr->next = new Node; // create the next node ...
			rcurr->next->prev = rcurr;
			rcurr = rcurr->next; // Then move to it
			lcurr = lcurr->next; // Same for the source node

			rcurr->stId = lcurr->stId;
			rcurr->stName = lcurr->stName;
			rcurr->stEmail = lcurr->stEmail;
			rcurr->stAge = lcurr->stAge;
		}
		// Make the list circular
		rcurr->next = rightTop;
		rightTop->prev = rcurr;
	}
}
void CircularDLL::destroy(Node*& top)
{
	if (top == NULL)
		return;
	
	Node *origTopAddr = top;
	Node *priorNode;

	do {
		priorNode = top;
		top = top->next;
		delete priorNode;
	} while (top != origTopAddr);

	top = NULL;
}
void CircularDLL::insertBeforeFirst(int id, const string& name, const string& email, int age)
{
	Node *newNode = new Node;
	newNode->stId = id;
	newNode->stName = name;
	newNode->stEmail = email;
	newNode->stAge = age;
	if (top == NULL)
	{
		top = newNode;
		return;
	}
	if (top->next == top) // One node
	{
		newNode->prev = top;
		newNode->next = top;
		top->next = newNode;
		top->prev = newNode;
		top = newNode;
	}
	else // More than one
	{
		newNode->prev = top->prev;
		newNode->next = top;
		top->prev = newNode;
		top = newNode;
	}

	/*newNode->prev = top->prev;
	newNode->next = top->next;

	top->prev = newNode;
	top->next = newNode;
	top = newNode;*/

}
void CircularDLL::insertAfterFirst(int id, const string& name, const string& email, int age)
{
	Node *newNode = new Node;
	newNode->stId = id;
	newNode->stName = name;
	newNode->stEmail = email;
	newNode->stAge = age;
	if (top == NULL)
	{
		top = newNode;
		return;
	}
	
	newNode->prev = top;
	newNode->next = top->next;

	if (top->prev == top) // If the list was just one node.
	{
		top->prev = newNode; // top's prev is now newNode, otherwise it shouldn't change.
	}
	else
	{
		top->next->prev = newNode;
	}
	top->next = newNode;

	/*newNode->prev = top;
		if (top->next == top) // only one node in the list
		{
		newNode->next = top; // This will be the second node, and to make it circular its next will point to top.
		top->prev = newNode;
		top->next = newNode;
		}
		else // More than one node.
		{
		newNode->next = top->next;
		top->next->prev = newNode; // The second node's previous needs to point to this node, as it goes 'inbetween' the old second and top
		}
		top->next = newNode;*/

}
void CircularDLL::insertBeforeLast(int id, const string& name, const string& email, int age)
{
	Node *newNode = new Node;
	newNode->stId = id;
	newNode->stName = name;
	newNode->stEmail = email;
	newNode->stAge = age;

	if (top == NULL)
	{
		top = newNode;
		return;
	}

	Node *lastNode = top->prev;
	newNode->next = lastNode;
	newNode->prev = lastNode->prev;
	lastNode->prev->next = newNode;
	if (top->prev == top) // A list of one
	{
		top = newNode;
	}
	lastNode->prev = newNode;

}
void CircularDLL::insertAfterLast(int id, const string& name, const string& email, int age)
{
	Node *newNode = new Node;
	newNode->stId = id;
	newNode->stName = name;
	newNode->stEmail = email;
	newNode->stAge = age;

	if (top == NULL)
	{
		top = newNode;
		return;
	}
	if (top->prev == top) // Only one node in the list
	{
		top->next = newNode;
		top->prev = newNode;
		newNode->next = top;
		newNode->prev = top;
	}
	else // More than one node
	{
		newNode->prev = top->prev;
		top->prev->next = newNode;
		top->prev = newNode;
		newNode->next = top; // Or if you want, top->prev->next..
	}
}
void CircularDLL::remove(int id)
{

	if (top == NULL) // Empty list
	{
		return;
	}
	Node *nodeToRemove = top, *nodePrior = NULL;
	while (nodeToRemove->stId != id && nodeToRemove->next != top) // Infinite loop in a cll of 1 node, if that node doesn't match
	{
		nodePrior = nodeToRemove;
		nodeToRemove = nodeToRemove->next;
	}
	if (!nodePrior) // List of one
	{
		delete top;
		top = NULL;
	}
	else
	{
		nodePrior->next = nodeToRemove->next;
		nodeToRemove->next->prev = nodePrior;
	}
}
void CircularDLL::print() const
{
	if (top == NULL)
	{
		return;
	}

	Node *currNode = top;
	do {
		cout << "Node (addr " << ((int*)currNode) << "): " << currNode->stName << " <" <<
																													currNode->stEmail << "> age " << currNode->stAge << ", ID " << currNode->stId << ")" << endl;
		currNode = currNode->next;
	} while (currNode != top);
}
bool CircularDLL::search(int id) const
{
	if (top == NULL)
		return false;


	Node *currentNode = top;
	do
	{
		if (currentNode->stId == id)
			return true;
		currentNode = currentNode->next;
	} while (currentNode != top);

	return false;
}
void CircularDLL::insertDataFromFile(const string& filename)
{
	ifstream dataIfs(filename.c_str());
	if (!dataIfs)
	{
		cerr << "Error: file \"" << filename << "\" could not be opened." << endl;
		return;
	}

	int id;
	string name, email;
	int age;

	while (dataIfs >> id >> name >> email >> age)
	{
		this->insertAfterLast(id, name, email, age);
	}


	dataIfs.close();
}
