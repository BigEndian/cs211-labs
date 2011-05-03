#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>
#include "Security.h"

using namespace std;

const string Security::alphabet = "abcdefghijklmnopqrstuvwxyz";

// Private functions
inline bool Security::HandleFileOpening()
{

	this->fstreamIn.open(  this->inFilename .c_str() );
	this->fstreamOut.open( this->outFilename.c_str()  );
	if (!this->fstreamIn) // if the file wasn't found, or wasn't able to be opened for another reason
	{
		cerr << "File " << this->inFilename << " does not exist!" << endl; // Make the user wary
	}

	return ( ((bool) fstreamIn) && ((bool) fstreamOut) ); // Returns true if both opened propery, false otherwise.
}
inline void Security::HandleFileClosing()
{
	this->fstreamIn.close();
	this->fstreamOut.close();
}

// Public functions

// Setter functions
Security& Security::setRotationNumber(int rotationNumber)
{
	this->rotationNumber = rotationNumber;
	return *this;
}
Security& Security::setInFilename(const string& inFilename)
{
	this->inFilename = inFilename;
	return *this;
}
Security& Security::setOutFilename(const string& outFilename)
{
	this->outFilename = outFilename;
	return *this;
}
Security& Security::setCryptogram(const string& cryptogram)
{
	this->cryptogram = cryptogram;
	return *this;
}
Security& Security::setMethod(const METHOD method)
{
	this->method = method;
	return *this;
}

// Getter functions
int Security::getRotationNumber() const
{
	return this->rotationNumber;
}
string Security::getCryptogram() const
{
	return this->cryptogram;
}

// Static functions
void Security::sRotateWordForward(string& word, unsigned int rotationNumber)
{
	for (unsigned int i = 0; i < word.length(); i++)
	{
		bool isCharLower = (bool) islower(word[i]);
		unsigned int distanceToEnd = 0; // Used to store how far the character is from z/Z

		if (!isalpha( word[i] )) // If the character isn't alpha, we'll just ignore it
			continue;

		if (isCharLower) // character is lowercase
		{
			distanceToEnd = 'z' - word[i];
			if ( distanceToEnd < rotationNumber ) // If we have to rotate beyond the limit
			{
				word[i] = 'a' + (rotationNumber - distanceToEnd - 1);
			}
			else // Not beyond limit
			{
				word[i] += rotationNumber;
			}
		}
		else             // character is uppercase
		{
			distanceToEnd = 'Z' - word[i];
			if ( distanceToEnd < rotationNumber ) // If we have to rotate beyond the limit
			{
				word[i] = 'A' + (rotationNumber - distanceToEnd - 1); // Properly handle it by ignoring the distance to end and calculating from beg. instead.
			}
			else
			{
				word[i] += rotationNumber; // We won't go over bounds, just rotate forward
			}
		}
	}
}
void Security::sRotateWordBackward(string& word, unsigned int rotationNumber)
{
	Security::sRotateWordForward(word, 26 - rotationNumber); // Just rotate 26 - rotationNumber forward. It works :D
}

void Security::sEncryptWord(string& word, const string& baseTable, const string& cryptogram)
{
	// Crypto table and base table both must be all lowercase.
	// I will not check this here, only in main.
	unsigned int correspondingIndex;
	char lowerLetter; // The current letter, forced to be lowercase

	for (unsigned int i = 0; i < word.length(); i++)
	{
		if (!isalpha(word[i])) // Skip non alphas
		{
			continue;
		}
		// This was originally implemented to handle both uppercase and lowercase properly,
		// however the assignment initially states to ignore case and go with lowercase.
		// so that's what was done.

		lowerLetter = tolower(word[i]); // Get the current letter as lowercase, and store it
		correspondingIndex = baseTable.find( lowerLetter ); // Find the letter in the base table. This is the matching index.
		word[i] = cryptogram[ correspondingIndex ]; // store the corresponding character in the current index. i.e. overwrite the current letter with the corr. letter.
	}
}
void Security::sDecryptWord(string& word, const string& baseTable, const string& cryptogram)
{
	Security::sEncryptWord(word, cryptogram, baseTable); // reverse the tables. Works fine. :D
}

// non-static Functions used on words.
// These just call the static functions using the respective object's internal variables
void Security::EncryptWord(string& word) const
{
	Security::sEncryptWord(word, alphabet, cryptogram);
}
void Security::DecryptWord(string& word) const
{
	Security::sDecryptWord(word, alphabet, cryptogram);
}
void Security::RotateWordForward(string& word) const
{
	Security::sRotateWordForward(word, this->rotationNumber);
}
void Security::RotateWordBackward(string& word) const
{
	Security::sRotateWordBackward(word, this->rotationNumber);
}

// File functions
void Security::PerformMethod()
{
	if (!this->HandleFileOpening()) // If we couldn't open the input file or output file ...
	{
		return; // Just end the function now
	}

	string word;
	char buffer[128];
	while (!fstreamIn.eof())
	{
		fstreamIn.get(buffer, sizeof(char)*128, '\0'); // Read 128 bytes, delimited by a NULL
		word = buffer; // Set word using the buffer. convert from char* to string
		if ( method == METHOD_ENC )
		{
			this->EncryptWord(word);
		}
		else if ( method == METHOD_DEC )
		{
			this->DecryptWord(word);
		}
		else if (method == METHOD_ROTFORWARD )
		{
			this->RotateWordForward(word);
		}
		else if (method == METHOD_ROTBACKWARD )
		{
			this->RotateWordBackward(word);
		}

		fstreamOut << word; // Write the block
	}
	this->HandleFileClosing(); // Close the files
}
