#include <iostream>

using namespace std;

bool isFib(int, int, int);
int gcd(int, int);

bool isFib(int a, int x=0, int y=1)
{
	//cout << "x, y => " << x << ", " << y << endl;
	if ( a == y )
		return true;
	else if ( a < y ) // Passed the range
		return false;
	else
		return isFib(a, y, x+y);
}
int gcd(int x, int y)
{
	return (y == 0) ? x : gcd(y, x%y);
}
int main(int argc, char *argv[])
{
	int inputNum;
	bool result;

	do {
		cout << "Enter a number (enter a negative number to quit): ";
		cin >> inputNum;
		if (inputNum < 0)
			break;
		result = isFib(inputNum);
		if (!result)
			cout << "!!!!! Sorry " << inputNum << " is not a Fibonacci number" << endl;
		else
			cout << "Yes, you got it, " << inputNum << " is a Fibonacci number" << endl;
		cout << endl;
	} while (true);
	cout << endl;
	cout << "(*Thanks - Have a good Day*)" << endl;
	return 0;
}
