#include "Key.h"

std::string encryption(char key[2][26], const std::string& word)
{
	std::string str1;
	for (char ch : word)
	{
		for (int j = 0; j < 26; j++)
		{
			if (ch == key[0][j])
			{
				str1 = str1 + key[1][j];
			}
		}
	}

	return str1;
}

std::string decryption(char key[2][26], const std::string& word)
{
	std::string str2;
	for (char ch : word)
	{
		for (int j = 0; j < 26; j++)
		{
			if (ch == key[1][j])
			{
				str2 = str2 + key[0][j];
			}
		}
	}

	return str2;
}