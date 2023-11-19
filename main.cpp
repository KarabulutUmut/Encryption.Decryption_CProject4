#include <iostream>
#include <string>
#include <cctype>
#include "Key.h"


std::string bigCase(std::string& word)
{
	for (char& c : word)
	{

		c = toupper(c);
	}	

	return word;
}

int main()
{
	char key[2][26] = { {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
							{'G', 'M', 'A', 'B', 'Z', 'T', 'Y', 'X', 'C', 'F', 'L', 'N', 'P', 'R', 'D', 'E', 'W', 'U', 'S', 'H', 'I', 'J', 'K', 'V', 'O', 'Q'}};

	char userInput;
	std::string word;
	std::string lastWord;
	bool isLastWordEncrypted = false;

	do
	{
		std::cout << "Do you want to encode or decode a word? (e/d), 'r' to reverse the last operation and 'q' to quit: ";
		std::cin >> userInput;

		switch (userInput)
		{
		case 'e':
			std::cout << "Word to be encrypted: " << "\n";
			std::cin >> word;
			bigCase(word);
			lastWord = encryption(key, word);
			std::cout << "Encrypted word is: " << lastWord << "\n";
			isLastWordEncrypted = true;
			break;

		case 'd':
			std::cout << "Word to be decrypted: " << "\n";
			std::cin >> word;
			bigCase(word);
			lastWord = decryption(key, word);
			std::cout << "Decrypted word is: " << lastWord << "\n";
			isLastWordEncrypted = false;
			break;

		case 'r':
			if (!lastWord.empty())
			{
				std::string reversedWord = isLastWordEncrypted ? decryption(key, lastWord) : encryption(key, lastWord);
				std::cout << (isLastWordEncrypted ? "Decrypted" : "Encrypted") << " word is: " << reversedWord << "\n";
			}
			else
			{
				std::cout << "No previous word to reverse.\n";
			}
			break;

		case 'q':
			std::cout << "Exiting the program.\n";
			return 0;

		default:
			std::cout << "\nInvalid input! Please enter 'e' to encrypt, 'd' to decrypt, 'r' to reverse last operation, or 'q' to quit.\n";
		}

	} while (true);

	return 0;
}