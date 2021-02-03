#ifndef CIPHER_H
#define CIPHER_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Cipher {
    public:
        virtual void encrypt(const ifstream &inputFile, ofstream &outputFile) = 0;
        virtual void decrypt(const ifstream &inputFile, ofstream &outputFile) = 0;
};


#endif