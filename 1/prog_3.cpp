#include <fstream>
#include <iostream>
#include <limits.h>

using namespace std;

void populate_array(ifstream& ifs, int out_array[], const int nIntsToRead);
void print_arr(const int arr[], const int size);
void reverse_arr(const int in_arr[], int out_arr[], const int size);
int nElementsInRange(const int array[], const int min, const int max, const int size);
int nElementsEvenlyDivisible(const int array[], const int divisor, const int size);
void printIndexesEvenlyDivisible(const int array[], const int divisor, const int size);

double arrayAverage(const int array[], const int size);
int arrayMin(const int array[], const int size);
bool keyExists(const int array[], const int key, const int size);

int main(int argc, char *argv[])
{
	const int SIZE = 10, MIN = 80, MAX = 100, DIVISOR = 5;

	int base_array[SIZE], reversed_array[SIZE];
	int key = 0;

	ifstream datafile("data2.txt");
	populate_array(datafile, base_array, SIZE);
	datafile.close();

	reverse_arr(base_array, reversed_array, SIZE);
	cout << "Base array: ";
	print_arr(base_array, SIZE);
	cout << "Reversed array: ";
	print_arr(reversed_array, SIZE);
	cout << endl;

	cout << "There are " << nElementsInRange(base_array, MIN, MAX, SIZE) << 
		" elements in base_array which are within the range of " << MIN << " and " << MAX << endl;
	cout << "There are " << nElementsEvenlyDivisible(base_array, DIVISOR, SIZE) <<
		" elements in base_array which are evenly divisible by " << DIVISOR << endl;
	cout << "The indexes of those elements which are evenly divisible by " << DIVISOR << " in the base array are: ";
	printIndexesEvenlyDivisible(base_array, DIVISOR, SIZE);

	cout << "The mean value of all elements in base array is: " << arrayAverage(base_array, SIZE) << endl;
	cout << "The minimum value of all elements in base array is: " << arrayMin(base_array, SIZE) << endl;
	cout << "Enter a value to see whether it is in base_array: ";
	cin >> key;
	cout << "The key \"" << key << "\" " << ((keyExists(base_array, key, SIZE) ? "does" : "does not")) << " exist in the base array" << endl;


	return 0;
}
void populate_array(ifstream& ifs, int out_array[], const int nIntsToRead) // This function assumes the file stream is open, and will not close it.
{
	for (int i = 0; (i < nIntsToRead) && !ifs.eof(); i++)
	{
		ifs >> out_array[i];
	}
}
void print_arr(const int arr[], const int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void reverse_arr(const int in_arr[], int out_arr[], const int size)
{
	for (int i = size-1; i >= 0; i--)
	{
		out_arr[size-i-1] = in_arr[i];
	}
}
int nElementsInRange(const int array[], const int min, const int max, const int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if ( (array[i] >= min) && (array[i] <= max) )
			count++;
	}
	return count;
}
int nElementsEvenlyDivisible(const int array[], const int divisor, const int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if ( array[i] % divisor == 0 )
			count++;
	}
	return count;
}
double arrayAverage(const int array[], const int size)
{
	double average = 0.0;
	for (int i = 0; i < size; i++)
		average += (double)array[i];
	average /= size;
	return average;
}
int arrayMin(const int array[], const int size)
{
	int min = array[0];
	for (int i = 1; i < size; i++)
	{
		if ( array[i] < min )
			min = array[i];
	}
	return min;
}
void printIndexesEvenlyDivisible(const int array[], const int divisor, const int size)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] % divisor == 0)
			cout << i << " ";
	}
	cout << endl;
}
bool keyExists(const int array[], const int key, const int size)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == key)
			return true;
	}
	return false;
}
