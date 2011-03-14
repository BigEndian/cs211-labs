#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

void Append(vector<string>& V, const string& data);
void Delete(vector<string>& V, const unsigned int index);
void Insert(vector<string>& V, const string& data, const unsigned int index);
void Print(const vector<string>& V, ostream& o);

int main(int argc, char *argv[])
{
	ifstream ifs("data.txt");
	vector<string> V;
	string command, data;
	unsigned int position;

	if (!ifs)
	{
		cerr << "File data.txt does not exist!" << endl;
		return 1;
	}

	while (ifs >> command)
	{
		if (command == "Append")
		{
			ifs >> data;
			Append(V, data);
		}
		else if (command == "Insert")
		{
			ifs >> data >> position;
			Insert(V, data, position);
		}
		else if (command == "Delete")
		{
			ifs >> position;
			Delete(V, position);
		}
		else if (command == "Print")
		{
			Print(V, cout);
		}
		else
		{
			cerr << "Invalid command: " << command;
		} // Invalid command
	}
	return 0;
}
void Append(vector<string>& V, const string& data)
{
	V.push_back(data);
}
void Delete(vector<string>& V, const unsigned int index)
{
	if ( V.size() > index )
		V.erase(V.begin() + index);
	else
		cerr << "Error @ " << index << endl;
}
void Insert(vector<string>& V, const string& data, const unsigned int index) // In our usage of this function in this program, this fuction never does anything
{
	if ( index <= V.size() ) // If index is valid
		V.insert(V.begin() + index, data); // Insert, otherwise do nothing
	else
		cerr << "Error @ " << index << endl;
}
void Print(const vector<string>& V, ostream& o)
{
	for (unsigned int i = 0; i < V.size(); i++)
		o << V[i] << " ";
	o << endl;
}
