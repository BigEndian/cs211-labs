// Assignment number 1: Security
// Author: <REDACTED>
// Email : <REDACTED>
// Date Written : Early February 2011 until February 23rd, 2011
// Purpose: To either rotate characters in a certain file a certain direction and distance, or 
// encrypt/decrypt them according a cryptogram, the results of either being stored in a file.
// For rotation, both direction and a distance must be specified, i.e. rotate 13 characters backwards.
// For the cryptogram, encryption or decryption must be specified,along with a raw cryptogram, or a file containing the cryptogram,
// in which case the filename must end in ".txt"

// Input: (Most) inputs from the user come from STDIN (i.e. filenames and rot number, and sometimes the cryptogram).
// Some are stored in files, such as the input file contents used, and the cryptogram file (if specified)

// Output:

#include <iostream>
#include <string>
#include "Security.h" 


using namespace std;

string promptForCryptogram();

int main(int argc, char *argv[])
{
	// Purpose: to prompt the user for various inputs necessary to perform the tasks required by the program.
	// Uses the Security class outlined and implemented in Security.h and Security.cpp respectively in order to
	// perform these tasks.

	Security SecurityInstance;

	unsigned int method; // Used to store the method we perform, i.e. forward/backward rot, enc/dec
	string inFilename, outFilename, cryptogram;
	unsigned int rotNumber;


	cout << "Enter the method to use: 1 for encryption, 2 for decryption, 3 for forward rotation, or 4 for backward rotation: ";

	do 
	{
		cin >> method;
	} while (method > 4 || method < 1); // Get the method and some associated information

	cout << "Enter the input file: ";
	cin >> inFilename;
	cout << "Enter the output file: ";
	cin >> outFilename;

	SecurityInstance.setInFilename(inFilename);
	SecurityInstance.setOutFilename(outFilename);

	if (method == 1 || method == 2) // Encryption or decryption
	{
		cryptogram = promptForCryptogram();
		SecurityInstance.setCryptogram(cryptogram);
	}
	else if (method == 3 || method == 4) // Forward or backward rotation
	{
		cout << "Enter the rotation number: ";

		do
		{
			cin >> rotNumber;
		} while (rotNumber < 1 || rotNumber > 25); // Make sure the rotation number is within but not touching 0-26

		SecurityInstance.setRotationNumber(rotNumber);
	}

	SecurityInstance.setMethod((Security::METHOD) method); // Pass the method
	SecurityInstance.PerformMethod(); // And perform what was specified


	return 0;
}

string promptForCryptogram()
{
	string cryptogram;   // Used to store both the cryptogram AND the cryptogram filename if that's what's given, although not at the same time.
	ifstream cryptoIfs;  // Used if a *.txt is specified

	cout << "Enter the file to find the cryptogram in, ending with .txt, or enter the cryptogram by itself: "; // Prompt
	// Validity loop
	do {
		cin >> cryptogram; // Read the cryptogram (or file)
		if ( cryptogram.length() > 4 ) // i.e. more than .txt, could be a cryptogram or a filename
		{
			if (cryptogram.substr( cryptogram.length() - 4 ) == ".txt") // If they gave us a filename
			{
				cryptoIfs.open( cryptogram.c_str() ); // Open the file
				if (!cryptoIfs) // If it didn't exist
				{
					cerr << "File " << cryptogram << " does not exist, try again." << endl;
					continue;
				}
				cryptoIfs >> cryptogram;
				cryptoIfs.close();
			}
		}

		if (cryptogram.length() == 26) // If they gave us a proper length crypto
			break;                       // End loop

	} while (true);

	return  cryptogram; // And finally return the cryptogram
}
