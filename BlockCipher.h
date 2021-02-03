#ifndef BLOCKCIPHER_H
#define BLOCKCIPHER_H

#include "Cipher.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class BlockCipher : public Cipher {
    public:
        BlockCipher(const ifstream &keyFile);
        void encrypt(const ifstream &inputFile, ofstream &outputFile);
        void decrypt(const ifstream &inputFile, ofstream &outputFile);
    private:
        const ifstream &keyFile;
};

#endif