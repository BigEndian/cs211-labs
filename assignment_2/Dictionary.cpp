#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
#include "Dictionary.h"

Dictionary::Dictionary() : maxWordsInDict(10000), maxWordsPerFile(10000)
{
	// Purpose: to initialize the dictionary with 10000 being both
	//          the max number of words in the dictionary, and in any file.

	totalWordsInDict = 0;
	for (int i = 0; i < 26; i++)
	{
		numOfWordsInFile[i] = 0;
	}
} // END Dictionary()
Dictionary::Dictionary(int dictMaxWords, int fileMaxWords) : maxWordsInDict(dictMaxWords), maxWordsPerFile(fileMaxWords)
{
	// Purpose: to initialize the dictionary with dictMaxWords being used as the value for the
	//          maximum number of words in the dictionary, and fileMaxWords being used as the 
	//          maximum number of words in any particular file.

	totalWordsInDict = 0;
	for (int i = 0; i < 26; i++)
	{
		numOfWordsInFile[i] = 0;
	}
} // END Dictionary(int, int)
string Dictionary::toLowerCase(const string& word)
{
	// Purpose: to take any string and return a modified copy,
	//          in which all alphabetical characters are lowercase.

	string convWord = word; // Duplicate the passed string
	for (unsigned int i = 0; i < convWord.length(); i++) // Iterate through it
	{
		if (isalpha(convWord[i])) // If the current letter is alphabetical
		{
			convWord[i] = (char) tolower(convWord[i]); // Convert it to lowercase, overwriting the current letter with this lowercase value.
		}
	}
	return convWord; // return the lowercased word.
} // END toLowerCase
bool Dictionary::wordIsValid(const string& word)
{
	// Purpose: To check word validity.
	//          A word is valid if it is 1 character or longer and starts with
	//          an alphabetical character.

	return (( word.length() != 0 ) && ( isalpha(word[0]) ));
} // END wordIsValid
unsigned int Dictionary::getCorrespondingIndex(const string& word)
{
	// Purpose: to get the index corresponding to the first letter
	//          off the passed word. a = 0, b = 1, B = 1, etc
	return (unsigned int) (tolower(word[0]) - 'a');
} // END getCorrespondingIndex
string Dictionary::getFilenameByWord(const string& word)
{
	// Purpose: to get the corresponding filename, using the passed word.
	string filename = " .txt";
	filename[0] = toupper(word[0]);
	return filename;
} // END getFilenameByWord

bool Dictionary::AddAWord(const string& word)
{
	// Purpose: to add a word to the corresponding file, making sure
	// that the word is valid and the word isn't already in the dictionary.

	switch (SearchForWord(word)) // IF the word is already there, fuck that shit.
	{
		case FILE_DOES_NOT_EXIST:
		case WORD_NOT_FOUND: 
			break; // Continue to the rest of the func. if the word isn't there.

		case WORD_IS_NOT_VALID: // If word is invalid or
		case WORD_FOUND:        // the word is already there
		default:                // or something else gets returned.. somehow.
			return failure;       // exit, failure.
	}

	const string wordToAdd = toLowerCase(word); // Convert the word to lower-case.

	unsigned int corrIndex = getCorrespondingIndex(wordToAdd); // Get correspond. index.
	
	if ( numOfWordsInFile[corrIndex] >= maxWordsPerFile ||
			 totalWordsInDict >= maxWordsInDict) // If we're at the limit for words in this file, or total words in dictionary
	{
		cerr << "Error: maximum number of words in file \"" << getFilenameByWord(wordToAdd) << ".txt\" reached, or " <<
				         "maximum number of words in dictionary reached. No more words can be added." << endl;
		return failure;
	}
	string outFilename = getFilenameByWord(wordToAdd);
	fstream outFstream( outFilename.c_str(), ios::out | ios::app ); // Open the corresponding file

	outFstream << wordToAdd << " "; // Add the word
	outFstream.close(); // Done with the file

	totalWordsInDict++; // We've added a word so increment totalWordsInDict
	numOfWordsInFile[corrIndex]++; // And the number of words in the file.

	return success;
} // END AddAWord

bool Dictionary::DeleteAWord(const string& word)
{
	// Purpose: Delete a word from the dictionary, including all of its duplicates, if it has any.
	//          The various things it does before ultimately performing that task
	//          however, aren't as simple as this function's name would suggest.

	switch (SearchForWord(word)) // Search for word in the dictionary.
	{
		case FILE_DOES_NOT_EXIST: // If the file doesn't exist
		case WORD_NOT_FOUND:      // or the word wasn't found
		case WORD_IS_NOT_VALID:   // Or the word wasn't valid:
			return failure;         // Failure

		case WORD_FOUND:          // Otherwise the word was found.
		default:                  // This should never be tripped unless I make a wrong return (hehe) in SearchForWord
			break;
	}

	const string wordToDel = toLowerCase(word);                      // Properly lowercased word
	const string filename = getFilenameByWord(wordToDel);            // Filename to use
	const unsigned int corrIndex = getCorrespondingIndex(wordToDel); // corresponding index for this word
	unsigned int nTimesWordAppeared = 0;                             // The number of times the certain word appeared
	fstream fileToModify(filename.c_str(), ios::in);                 // Fstream used to read in the words then write the ones that weren't matched

	string currentWord;                                              // Stores the current word
	vector<string> WordsToRetain;                                    // Stores all words that didn't match wordToDel

	while ( (fileToModify >> currentWord) )// && (words.size() < maxWordsPerFile) )
	{
		currentWord = toLowerCase(currentWord); // Convert to lowercase
		if (currentWord == wordToDel)           // If it matches, we don't need it
		{
			nTimesWordAppeared++;
			continue;                             // Skip to the next word (although there may not be one)
		}
		else                                    // Otherwise, add the word to the vector, to keep
		{
			WordsToRetain.push_back(currentWord);
		}
	}

	fileToModify.close();
	fileToModify.open(filename.c_str(), ios::out | ios::trunc); // Open and truncate

	for (unsigned int i = 0; i < WordsToRetain.size(); i++) // Iterate through the words vector
	{
		fileToModify << WordsToRetain[i] << " "; // Write the current word and a space to the file
	}

	fileToModify.close();
	numOfWordsInFile[corrIndex] -= nTimesWordAppeared; // Decrement by the number of words that weren't read into the vector.
	totalWordsInDict -= nTimesWordAppeared;            // Ditto

	return success;
} // END DeleteAWord
Dictionary::SEARCH_RESULT Dictionary::SearchForWord(const string& word)
{
	// Purpose: To search for a word to see if it's in the dictionary.
	//          I expanded its purpose however to help in other situations
	//          where I wanted more verbose error messages.
	//          If I did the error messages here, I wouldn't have a choice
	//          on whether they were printed, or I'd have to pass a bool (ugly)

	if (!wordIsValid(word))
	{
		return WORD_IS_NOT_VALID; // Invalid word
	}
	
	const string wordToFind = toLowerCase(word);
	string inFilename = getFilenameByWord(wordToFind);
	fstream inFstream( inFilename.c_str(), ios::in );

	if (!inFstream)
	{
		cerr << "Error: file \"" << getFilenameByWord(word) << "\" does not exist, and thus searching could not be performed." << endl;
		return FILE_DOES_NOT_EXIST;
	}

	string currentWord;

	while (inFstream >> currentWord)
	{
		currentWord = toLowerCase(currentWord);
		if (currentWord == wordToFind)
		{
			return WORD_FOUND;
		}
	}

	return WORD_NOT_FOUND;
} // END SearchForWord

bool Dictionary::SpellChecking(const string& filename)
{
	// Purpose: Check the file contents of filename to see if the words in it
	//          are in the dictionary or not already, thus "spell-checking" the file.

	fstream fileToCheck(filename.c_str(), ios::in); // Try to get the requested file
	if (!fileToCheck) // If we can't access it for whatever reason..
	{
		cerr << "Error: file \"" << filename << "\" does not exist, and thus spell-checking could not be performed." << endl;
		return failure; // .. break out of the function
	}

	string currentWord;
	while (fileToCheck >> currentWord) // Get a word
	{
		SEARCH_RESULT wordSearchResult = SearchForWord(currentWord);
		if (wordSearchResult == WORD_IS_NOT_VALID) // Invalid word, don't even consider it.
		{
			continue;
		}
		else if (wordSearchResult == FILE_DOES_NOT_EXIST || // If the file isn't there, it's not in the dictionary, or ..
			       wordSearchResult == WORD_NOT_FOUND)        // If the word was not found, it's also not in the dictionary
		{
			cout << "Word \"" << currentWord << "\" is not spelled correctly." << endl;
		}
		else // Word correct, this isn't necessary but I'll keep it here for now.
		{
			continue;
		}
	}
	return success;
} // END SpellChecking
// Static public functions
bool Dictionary::PrintAFileInDict(const string& filename)
{
	// Purpose: Print a file, with file words in each line. Printed to STDOUT.

	fstream fileToPrint(filename.c_str(), ios::in);
	if (!fileToPrint)
	{
		cerr << "Error: file \"" << filename << "\" does not exist, and thus printing could not be performed." << endl;
		return failure;
	}

	string currentWord;
	unsigned int currentWordNo = 0;
	const unsigned int wordsPerLine = 5;

	while (fileToPrint >> currentWord)
	{
		// This doesn't lowercase them first, it's a basically accurate version of the file.
		cout << currentWord;
		if ((++currentWordNo % wordsPerLine) == 0)
		{
			cout << endl;
		}
		else
		{
			cout << " ";
		}
	}
	if (currentWordNo % wordsPerLine != 0) // If we didn't get to print a final endline, print one.
	{
		cout << endl;
	}
	return success;
} // END PrintAFileInDict

bool Dictionary::InsertWordsIntoDict(const string& filename)
{
	// Purpose: insert the words found in the file specified into the dictionary

	fstream sourceFile(filename.c_str(), ios::in);
	if (!sourceFile)
	{
		cerr << "Error: file \"" << filename << "\" does not exist, and thus file-insertion could not be performed." << endl; 
		return failure;
	}

	string currentWord;

	while (sourceFile >> currentWord)
	{
		if (totalWordsInDict >= maxWordsInDict) // If we're over the limit, don't keep calling the add a word function, it's a waste of time.
		{
			cerr << "Error: max words in dictionary (" << maxWordsInDict << ") has been reached. Complete insertion failed." << endl;
			return failure; // As usual boolean values fail to suffice in certain contexs. We may have inserted SOME, so it's not a true absolute failure.
		}
		this->AddAWord(currentWord); // Add the word, this handles incrementation for us.
	}
	sourceFile.close();
	return success;
}
void Dictionary::ProcessTransactionFile(const string& filename)
{
	// Purpose: To process a transaction file and perform what it specifies.

	ifstream transactFile(filename.c_str());
	if (!transactFile)
	{
		cerr << "Error: Transaction file \"" << filename << "\" does not exist." << endl;
		return;
	}

	string command, data;

	while (transactFile >> command >> data)
	{
		if (command == "AddW")
		{
			this->AddAWord(data);
		}
		else if (command == "DelW")
		{
			this->DeleteAWord(data);
		}
		else if (command == "SearchW")
		{
			SEARCH_RESULT wordSearchResult = SearchForWord(data);
			if (wordSearchResult == WORD_NOT_FOUND ||
				  wordSearchResult == FILE_DOES_NOT_EXIST)
			{
				cout << "Word \"" << data << "\" was not found." << endl;
			}
			else if (wordSearchResult == WORD_FOUND)
			{
				cout << "Word \"" << data << "\" was found." << endl;
			}
			else
			{
				cout << "Word \"" << data << "\" is not valid." << endl;
			}
		}
		else if (command == "InsertF")
		{
			this->InsertWordsIntoDict(data);
		}
		else if (command == "PrintF")
		{
			this->PrintAFileInDict(data);
		}
		else if (command == "SpellCheck")
		{
			this->SpellChecking(data);
		}
	}

	transactFile.close();
}
