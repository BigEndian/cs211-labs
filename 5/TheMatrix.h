#include <iostream>
#include <fstream>

using namespace std;

class TheMatrix;

TheMatrix operator+(const TheMatrix& m1, const TheMatrix& m2);
TheMatrix operator-(const TheMatrix& m1, const TheMatrix& m2);
TheMatrix operator*(const TheMatrix& m1, const TheMatrix& m2);
TheMatrix operator/(const TheMatrix& m1, const TheMatrix& m2);
ifstream&  operator>>(ifstream& ifs, const TheMatrix& m);
ostream&   operator<<(ostream& os, const TheMatrix& m);


class TheMatrix
{
	// He wants us to use friend functions but this is a public datamember..

	public: 
		TheMatrix();
		~TheMatrix();
		friend TheMatrix operator+(const TheMatrix& m1, const TheMatrix& m2);
		friend TheMatrix operator-(const TheMatrix& m1, const TheMatrix& m2);
		friend TheMatrix operator*(const TheMatrix& m1, const TheMatrix& m2);
		friend TheMatrix operator/(const TheMatrix& m1, const TheMatrix& m2);
		friend ifstream&  operator>>(ifstream& ifs, const TheMatrix& m);
		friend ostream&   operator<<(ostream& os, const TheMatrix& m);
		int M[5][5];
};

TheMatrix::TheMatrix()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			this->M[i][j] = 0;
}
TheMatrix::~TheMatrix()
{
	// Nothing to do..
	// What's the point
	// Nihilism, etc.
}

TheMatrix operator+(const TheMatrix& m1, const TheMatrix& m2)
{
	TheMatrix result;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			result.M[i][j] = m1.M[i][j] + m2.M[i][j];
		}
	}
	return result;
}
TheMatrix operator-(const TheMatrix& m1, const TheMatrix& m2)
{
	TheMatrix result;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			result.M[i][j] = m1.M[i][j] - m2.M[i][j];
		}
	}
	return result;
}
TheMatrix operator*(const TheMatrix& m1, const TheMatrix& m2)
{
	TheMatrix result;
	// This algorithm isn't mine, it was found at
	// http://www.edcc.edu/faculty/paul.bladek/Cmpsc142/matmult.htm
	// I take no credit for it, even though
	// my attempts were close ( honestly :< )

/*	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				result.M[i][j] = m1.M[i][k] * m2.M[k][j];
			}
		}
	}*/
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			result.M[i][j] = m1.M[i][j] * m2.M[i][j];
		}
	}
	return result;
}
TheMatrix operator/(const TheMatrix& m1, const TheMatrix& m2)
{
	TheMatrix result;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (m2.M[i][j] == 0)
			{
				result.M[i][j] = 0;
				continue;
			}
			result.M[i][j] = m1.M[i][j] / m2.M[i][j];
		}
	}
	return result;
}
ifstream& operator>>(ifstream& is, TheMatrix& tm)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			is >> tm.M[i][j];
		}
	}
	return is;
}
ostream& operator<<(ostream& os, const TheMatrix& tm)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			os << tm.M[i][j] << " ";
		}
		os << endl;
	}
	os << endl;
	return os;
}
