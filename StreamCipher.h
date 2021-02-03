#ifndef STREAMCIPHER_H
#define STREAMCIPHER_H

#include "Cipher.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class StreamCipher : public Cipher {
    public:
        StreamCipher(const ifstream &keyFile);
        void encrypt(const ifstream &inputFile, ofstream &outputFile);
        void decrypt(const ifstream &inputFile, ofstream &outputFile);
    private:
        const ifstream &keyFile;
};

#endif