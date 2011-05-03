#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class Security
{
		// Author: <REDACTED>
		// Email : <REDACTED>
		// Date Written: Early February 2011 until February 23rd, 2011
		// Purpose: To facilitate bidirectional rotation with variable distances on an input file,
		// whose result will be stored in an output file, as well as facilitate encryption/decryption
		// with a cryptogram.

	public:
		// Used to easily differentiate between which method to use.
		// This helps to prevent a whole bunch of boilerplate code
		// that would otherwise appear. i.e. EncryptFile, DecryptFile, et al.
		enum METHOD {
			METHOD_ENC=1,
			METHOD_DEC=2,
			METHOD_ROTFORWARD=3,
			METHOD_ROTBACKWARD=4
		};

	private:
		string     inFilename;  // Input filename
		string     outFilename; // Output filename
		ifstream   fstreamIn;   // Input filestream
		ofstream   fstreamOut;  // Output filestream
		METHOD     method;      // Method to use on the input file to generate the output file's contents

		// Rotation
		int   rotationNumber;

		// Encryption/decryption
		static const string alphabet; // Used as a base table of sorts.
		string cryptogram;            // The cryptogram, used with the alphabet
		
		// File functions
		inline bool HandleFileOpening();
		inline void HandleFileClosing();

	public:
		// No-arg constructor
		Security() { 
			this->inFilename = "in.txt";
			this->outFilename = "out.txt";
			this->method = METHOD_ENC;
			this->cryptogram = "zyxwvutsrqponmlkjihgfedcba";
		};

		// Setter functions
		Security& setRotationNumber(int rotationNumber);
		Security& setInFilename(const string& inFilename);
		Security& setOutFilename(const string& outFilename);
		Security& setCryptogram(const string& cryptoTable);
		Security& setMethod(const METHOD method);

		// Getter functions
		int getRotationNumber() const;
		string getCryptogram() const;

		// Function which performs what the method specifies.
		// The summation of the class's parts in a way.
		void PerformMethod();

		// Functions which just handle words
		void EncryptWord(string& word)        const;
		void DecryptWord(string& word)        const;
		void RotateWordForward(string& word)  const;
		void RotateWordBackward(string& word) const;


		// Static methods.
		// The corresponding non-static methods call these.
		static void sEncryptWord(string& word, const string& baseTable, const string& cryptoTable);
		static void sDecryptWord(string& word, const string& baseTable, const string& cryptoTable);
		static void sRotateWordForward(string& word, unsigned int rotationNumber);
		static void sRotateWordBackward(string& word, unsigned int rotationNumber);
};

