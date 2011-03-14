#include <iostream>

using namespace std;


void MultMatrix(int a[5][5], int b[5][5])
{
	int RESULT[5][5];

	/*RESULT[0][0] =    (a[0][0] * b[0][0]);
		RESULT[0][0] += (a[0][1] * b[1][0]);
	
	RESULT[0][1] =    (a[0][0] * b[0][1]);
		RESULT[0][1] += (a[0][1] * b[1][1]);
	
	RESULT[1][0] =    (a[1][0] * b[0][0]);
		RESULT[1][0] += (a[1][1] * b[1][0]);
	
	RESULT[1][1] =    (a[1][0] * b[0][1]);
		RESULT[1][1] += (a[1][1] * b[1][1]);*/

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << RESULT[i][j] << " ";
			RESULT[i][j] = 0;
		}
		cout << endl;
	}

	for (int RES_I = 0; RES_I < 5; RES_I++)
	{
		for (int RES_J = 0; RES_J < 5; RES_J++)
		{
			for (int LONE_J = 0; LONE_J < 5; LONE_J++)
			{
				RESULT[RES_I][RES_J] += (a[RES_I][LONE_J] * b[LONE_J][RES_J]);
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << RESULT[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int a[5][5] = { {1,2,3,4,5},
									{2,3,4,5,1},
									{3,4,5,1,2},
									{4,5,1,2,3},
									{5,1,2,3,4}
								};

	int b[5][5] = { {5,4,3,2,1},
									{4,3,2,1,5},
									{3,2,1,5,4},
									{2,1,5,4,3},
									{1,5,4,3,2}
								};

	MultMatrix(a, b);
	return 0;
}
