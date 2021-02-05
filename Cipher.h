#ifndef CIPHER_H
#define CIPHER_H

#include <fstream> // ifstream, ofstream
#include <string> // string

class Cipher {
    public:
        virtual void encrypt(std::ifstream &inputFile, std::ofstream &outputFile) = 0;
        virtual void decrypt(std::ifstream &inputFile, std::ofstream &outputFile) = 0;

    protected:
        std::string fileToString(std::ifstream &file);
};

#endif