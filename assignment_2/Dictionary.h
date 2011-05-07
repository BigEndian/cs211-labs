#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <ctype.h>


using namespace std;

class Dictionary
{
	// Author: <REDACTED>
	// Email Address: <REDACTED>
	// Date Written: Between February 2011 and March 2011
	// Purpose: To simulate a word repository of sorts, with each word sorted by first letter, into their own
	// separate files (A.txt, B.txt, et al.), and perform various modifications to the data contained in those files:
	// i.e. searching, deleting, adding, and checking files to see if the words are stored in this 'repository' of sorts.

	private:
		const    unsigned int maxWordsInDict;
		const    unsigned int maxWordsPerFile;
		unsigned          int totalWordsInDict;
		unsigned          int numOfWordsInFile[26];

		const static bool success = true ; 
		const static bool failure = false;

		// Word functions
		static string toLowerCase(const string& word);
		static bool wordIsValid(const string& word);
		static unsigned int getCorrespondingIndex(const string& word);
		static string getFilenameByWord(const string& word);

	public:
		enum SEARCH_RESULT {
			FILE_DOES_NOT_EXIST,
			WORD_IS_NOT_VALID,
			WORD_NOT_FOUND,
			WORD_FOUND
		};

		Dictionary();
		Dictionary(int dictMaxWords, int fileMaxWords);

		// Static public functions
		// These functions can be referenced
		// As if they were member functions as well, i.e. (Dictionary()).PrintAFileInDict("someFile.txt");

		static bool PrintAFileInDict( const string& filename ); // There's no reason to have this as non-static, it doesn't even touch the object's member(s), hehe.

		// Non-static public functions
		bool AddAWord               ( const string& word);
		bool DeleteAWord            ( const string& wordToFind);
		SEARCH_RESULT SearchForWord ( const string& wordToFind);
		bool SpellChecking          ( const string& filename  );
		bool InsertWordsIntoDict    ( const string& filename  );
		void ProcessTransactionFile ( const string& filename  );
}; // END Dictionary
