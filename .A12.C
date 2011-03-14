//*****************************************************************************
// Assignment Number / Program name: A1

// Author: S. Afra Ghalebi

// Email Address: Ghale003@cougars.csusm.edu

// Date written: February 18, 2010

// Purpose: This program make Encryption and Decryption based on rot# and Cryptogram.
//*****************************************************************************

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void rotEncrypt(const vector<string> &vector1, vector<string> &vector2, int rotNum);
void rotDecrypt(const vector<string> &vector1, vector<string> &vector2, int rotNum);
void Cryptogram(const vector<string> &vector1, vector<string> &vector2);
void deCryptogram(const vector<string> &vector1, vector<string> &vector2);
void print(vector<string> vector);//prints in console and output

int main() 
{
  int choice, rotNum;
  string word;
  ifstream fin;
  fin.open("test.txt");//enter file name
  vector<string> vector1;
  vector<string> vector2;
  //fin>>word;
  while(!fin.eof())
    {
      fin>>word;
      vector1.push_back(word);
    }
  fin.close(); //closes file
  int q = 1;
  do{
    choice=0;
    cout<<"1.Encrypt\n2.Decrypt\nChoose one of the above: ";
    cin>>choice;
    if(choice==1)
      {
	choice=0;
	cout<<"1.rot\n2.Cryptogram\nChoose one of the above: ";
	cin>>choice;
	if(choice==1)
	  {
	    cout<<"Enter the rot number: \n\trot";
	    cin>>rotNum;
	    rotEncrypt(vector1, vector2, rotNum);
	  }
	if(choice==2)
	  {
	    //CRYPTOGRAM
	    Cryptogram(vector1, vector2);
	  }
      }
    if(choice==2)
      {
	choice=0;
	cout<<"1.rot\n2.deCryptogram\nChoose one of the above: ";
	cin>>choice;
	if(choice==1)
	  {
	    cout<<"Enter the rot number: \n\trot";
	    cin>>rotNum;
	    rotDecrypt(vector1, vector2, rotNum);
	  }
	if(choice==2)
	  {
	    //CRYPTOGRAM
	    deCryptogram(vector1, vector2);
	  }
      }
    choice=0;
    cout<<"Enter 1 to continue: ";
    cin>>q;
  }while(q==1);

}
void rotEncrypt(const vector<string> &vector1, vector<string> &vector2, int rotNum)
{
  string word;
  char new_letter;
  int i, j, wordSize, vecSize, vecSize2;
  vecSize = vector1.size();
  for(j=0; j<vecSize; j++)
    {
      word = vector1[j];
      wordSize = word.size();
      for(i=0; i<wordSize; i++)
	{
	  new_letter = word[i];
	  new_letter = rotNum + new_letter; 
	  word[i] = new_letter;
	}
      vector2.push_back(word);
    }
  print(vector2);
}

void rotDecrypt(const vector<string> &vector1, vector<string> &vector2, int rotNum)
{
  string word;
  char new_letter;
  int i, j, wordSize, vecSize, vecSize2;
  vecSize = vector1.size();
  for(j=0; j<vecSize; j++)
    {
      word = vector1[j];
      wordSize = word.size();
      for(i=0; i<wordSize; i++)
	{
	  new_letter = word[i];
	  new_letter = new_letter - rotNum; 
	  word[i] = new_letter;
	}
      vector2.push_back(word);
    }
  print(vector2);
}

void Cryptogram(const vector<string> &vector1, vector<string> &vector2)
{
  string word;
  char new_letter;
  long i, j, wordSize, vecSize, vecSize2;
  vecSize = vector1.size();
  for(j=0; j<vecSize; j++)
    {
      word = vector1[j];
      //cout<<word<<endl;
      wordSize = word.size();
      cout<<wordSize<<endl;
      for(i=0; i<wordSize; i++)
	{
	  new_letter = word[i];
	  cout<<"& " << new_letter<< " " << isalpha(new_letter) << endl;
	  if(isalpha(new_letter)==true)
	    {
	      if(isupper(new_letter)==true)
		{

		  if (new_letter == 'A')
		    new_letter = 'W';
		  else if(new_letter == 'B')
		    new_letter = 'Y';
		  else if(new_letter == 'C')
		    new_letter = 'I';
		  else if(new_letter == 'D')
		    new_letter = 'J';
		  else if(new_letter == 'E')
		    new_letter = 'K';
		  else if(new_letter == 'F')
		    new_letter = 'C';
		  else if(new_letter == 'G')
		    new_letter = 'U';
		  else if(new_letter == 'H')
		    new_letter = 'V';
		  else if(new_letter == 'I')
		    new_letter = 'D';
		  else if(new_letter == 'J')
		    new_letter = 'P';
		  else if(new_letter == 'K')
		    new_letter = 'Q';
		  else if(new_letter == 'L')
		    new_letter = 'L';
		  else if(new_letter == 'M')
		    new_letter = 'Z';
		  else if(new_letter == 'N')
		    new_letter = 'H';
		  else if(new_letter == 'O')
		    new_letter = 'T';
		  else if(new_letter == 'P')
		    new_letter = 'G';
		  else if(new_letter == 'Q')
		    new_letter = 'A';
		  else if(new_letter == 'R')
		    new_letter = 'B';
		  else if(new_letter == 'S')
		    new_letter = 'M';
		  else if(new_letter == 'T')
		    new_letter = 'X';
		  else if(new_letter == 'U')
		    new_letter = 'E';
		  else if(new_letter == 'V')
		    new_letter = 'F';
		  else if(new_letter == 'W')
		    new_letter = 'O';
		  else if(new_letter == 'X')
		    new_letter = 'N';
		  else if(new_letter == 'Y')
		    new_letter = 'R';
		  else if(new_letter == 'Z')
		    new_letter = 'S';
		}
	      else
		{
		  cout<<"# " << new_letter<< " ";

		  if (new_letter == 'a')
		    new_letter = 'w';
		  else if(new_letter == 'b')
		    new_letter = 'y';
		  else if(new_letter == 'c')
		    new_letter = 'i';
		  else if(new_letter == 'd')
		    new_letter = 'j';
		  else if(new_letter == 'e')
		    new_letter = 'k';
		  else if(new_letter == 'f')
		    new_letter = 'c';
		  else if(new_letter == 'g')
		    new_letter = 'u';
		  else if(new_letter == 'h')
		    new_letter = 'v';
		  else if(new_letter == 'i')
		    new_letter = 'd';
		  else if(new_letter == 'j')
		    new_letter = 'p';
		  else if(new_letter == 'k')
		    new_letter = 'q';
		  else if(new_letter == 'l')
		    new_letter = 'l';
		  else if(new_letter == 'm')
		    new_letter = 'z';
		  else if(new_letter == 'n')
		    new_letter = 'h';
		  else if(new_letter == 'o')
		    new_letter = 't';
		  else if(new_letter == 'p')
		    new_letter = 'g';
		  else if(new_letter == 'q')
		    new_letter = 'a';
		  else if(new_letter == 'r')
		    new_letter = 'b';
		  else if(new_letter == 's')
		    new_letter = 'm';
		  else if(new_letter == 't')
		    new_letter = 'x';
		  else if(new_letter == 'u')
		    new_letter = 'e';
		  else if(new_letter == 'v')
		    new_letter = 'f';
		  else if(new_letter == 'w')
		    new_letter = 'o';
		  else if(new_letter == 'x')
		    new_letter = 'n';
		  else if(new_letter == 'y')
		    new_letter = 'r';
		  else if(new_letter == 'z')
		    new_letter = 's';
		}

	    }
	  word[i] = new_letter;
	}
      cout << endl;
      vector2.push_back(word);
    }
  print(vector2);
}

void deCryptogram(const vector<string> &vector1, vector<string> &vector2)
{
  string word;
  char new_letter;
  int i, j, wordSize, vecSize, vecSize2;
  vecSize = vector1.size();
  for(j=0; j<vecSize; j++)
    {
      word = vector1[j];
      cout<<word<<endl;
      wordSize = word.size();
      cout<<wordSize<<endl;
      for(i=0; i<wordSize; i++)
	{
	  new_letter = word[i];
	  if(isalpha(new_letter)==true)
	    {
	      if(islower(new_letter)==true)
		{
		  if (new_letter == 'w')
		    new_letter = 'a';
		  else if(new_letter == 'y')
		    new_letter = 'b';
		  else if(new_letter == 'i')
		    new_letter = 'c';
		  else if(new_letter == 'j')
		    new_letter = 'd';
		  else if(new_letter == 'k')
		    new_letter = 'e';
		  else if(new_letter == 'c')
		    new_letter = 'f';
		  else if(new_letter == 'u')
		    new_letter = 'g';
		  else if(new_letter == 'v')
		    new_letter = 'h';
		  else if(new_letter == 'd')
		    new_letter = 'i';
		  else if(new_letter == 'p')
		    new_letter = 'j';
		  else if(new_letter == 'q')
		    new_letter = 'k';
		  else if(new_letter == 'l')
		    new_letter = 'l';
		  else if(new_letter == 'z')
		    new_letter = 'm';
		  else if(new_letter == 'h')
		    new_letter = 'n';
		  else if(new_letter == 't')
		    new_letter = 'o';
		  else if(new_letter == 'g')
		    new_letter = 'p';
		  else if(new_letter == 'a')
		    new_letter = 'q';
		  else if(new_letter == 'b')
		    new_letter = 'r';
		  else if(new_letter == 'm')
		    new_letter = 's';
		  else if(new_letter == 'x')
		    new_letter = 't';
		  else if(new_letter == 'e')
		    new_letter = 'u';
		  else if(new_letter == 'f')
		    new_letter = 'v';
		  else if(new_letter == 'o')
		    new_letter = 'w';
		  else if(new_letter == 'n')
		    new_letter = 'x';
		  else if(new_letter == 'r')
		    new_letter = 'y';
		  else if(new_letter == 's')
		    new_letter = 'z';
		}
	      if(isupper(new_letter)==true)
		{
		  if (new_letter == 'W')
		    new_letter = 'A';
		  else if(new_letter == 'Y')
		    new_letter = 'B';
		  else if(new_letter == 'I')
		    new_letter = 'C';
		  else if(new_letter == 'J')
		    new_letter = 'D';
		  else if(new_letter == 'K')
		    new_letter = 'E';
		  else if(new_letter == 'C')
		    new_letter = 'F';
		  else if(new_letter == 'U')
		    new_letter = 'G';
		  else if(new_letter == 'V')
		    new_letter = 'H';
		  else if(new_letter == 'D')
		    new_letter = 'I';
		  else if(new_letter == 'P')
		    new_letter = 'J';
		  else if(new_letter == 'Q')
		    new_letter = 'K';
		  else if(new_letter == 'L')
		    new_letter = 'L';
		  else if(new_letter == 'Z')
		    new_letter = 'M';
		  else if(new_letter == 'H')
		    new_letter = 'N';
		  else if(new_letter == 'T')
		    new_letter = 'O';
		  else if(new_letter == 'G')
		    new_letter = 'P';
		  else if(new_letter == 'A')
		    new_letter = 'Q';
		  else if(new_letter == 'B')
		    new_letter = 'R';
		  else if(new_letter == 'M')
		    new_letter = 'S';
		  else if(new_letter == 'X')
		    new_letter = 'T';
		  else if(new_letter == 'E')
		    new_letter = 'U';
		  else if(new_letter == 'F')
		    new_letter = 'V';
		  else if(new_letter == 'O')
		    new_letter = 'W';
		  else if(new_letter == 'N')
		    new_letter = 'X';
		  else if(new_letter == 'R')
		    new_letter = 'Y';
		  else if(new_letter == 'S')
		    new_letter = 'Z';
		}
	    }
	  word[i] = new_letter;
	}
      vector2.push_back(word);
    }
  print(vector2);
}


void print(vector<string> vector)
{
  ofstream fout;
  fout.open("Decrypt02.txt");
  int i, vecSize;
  vecSize = vector.size();
  cout<<"Vector Size is "<<vecSize<<". The sentence is: ";
  for(i=0; i<vecSize; i++)
    {
      cout<<vector[i];
      fout<<vector[i];
      fout<<" ";
      cout<<" ";
    }
  cout<<""<<endl;
  fout<<""<<endl;
}
