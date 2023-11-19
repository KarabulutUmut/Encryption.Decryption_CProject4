#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <string>

std::string encryption(char key[2][26], const std::string& word);

std::string decryption(char key[2][26], const std::string& word);

#endif