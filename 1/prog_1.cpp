#include <fstream> // fstream for file I/O
#include <iostream> // stream I/O
#include <iomanip> // I/O manipulation

using namespace std; // allow access to the standard namespace members without std::

void ProcessARow(const int n1, const int n2, const int n3, int& min, int& max, double& average);



int main(int argc, char *argv[])
{
	fstream datafile("data.txt", ios::in);
	int id, n1, n2, n3; // Used for each row's ID, and the three other integers on the line
	int min, max; // Used to store the min and max calculations for each row
	double average;
	// Print header
	cout << left << fixed;
	cout << setw(12) << "Stud. ID" << 
		setw(5) << "A1" << setw(5) << "A2" << setw(5) << "A3" << setw(5) << "Min" << setw(5) << "Max" << setw(5) << "Avg" << endl;
	cout << "=========================================" << endl;
	
	if (!datafile)
	{
		cerr << "File data.txt does not exist!" << endl;
	}
	while (datafile >> id >> n1 >> n2 >> n3)
	{
		ProcessARow(n1, n2, n3, min, max, average);
		cout << setw(12) << id << setw(5) << n1 << setw(5) << n2 << setw(5) << n3 <<
			setw(5) << min << setw(5) << max << setw(5) << setprecision(1) << average << setprecision(0) << endl;
	}
	datafile.close();
	return 0;
}
void ProcessARow(const int n1, const int n2, const int n3, int& min, int& max, double& average)
{
	average = ( n1 + n2 + n3 ) / 3.0;
	max = (n1 > n2) ? n1 : n2;
	max = (max > n3) ? max : n3;
	min = (n1 < n2) ? n1 : n2;
	min = (min < n3) ? min : n3;
}
