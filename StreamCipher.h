#ifndef STREAMCIPHER_H
#define STREAMCIPHER_H

#include "Cipher.h"

class StreamCipher : public Cipher {
    public:
        StreamCipher(std::ifstream &keyFile);
        void encrypt(std::ifstream &inputFile, std::ofstream &outputFile);
        void decrypt(std::ifstream &inputFile, std::ofstream &outputFile);
    private:
        std::ifstream &keyFile;
};

#endif