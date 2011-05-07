#include "Dictionary.h" // The Dictionary class
#include <iostream>
#include <string>
// Assignment Number: 2 (Dictionary class)
// Author: <REDACTED>
// Email Address: <REDACTED>
// Date written: Between February and March 2011
// Purpose: To use the dictionary class's ProcessTransactionFile
//          and the functions it calls to modify and use the Dictionary class's abilities
//          according to the contents of the file "TransactionFile.txt"
// Input:   Reads from a file named TransactionFile.txt, which contains various commands used
//          to call various functions existing in the Dictionary class, in order to do things like
//          insert words, delete words, find words, and do spell checking, into and through the dictionary.
// Output:  Prints the results of various commands as specified in the file TransactionFile.txt, for example:
//          The results of various word searches will be printed to STDOUT, or errors will be printed if various
//          files to use don't exist, according to the names specified in the transaction file.


int main(int argc, char *argv[])
{
	// Purpose: to initialize a dictionary and use it to process a
	//          transaction file, to modify the dictionary's contents.

	Dictionary d;
	d.ProcessTransactionFile("TransactionFile.txt");
	return 0;
}
