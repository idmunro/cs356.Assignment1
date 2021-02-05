#ifndef BLOCKCIPHER_H
#define BLOCKCIPHER_H

#include "Cipher.h"

class BlockCipher : public Cipher {
        std::ifstream &keyFile;
        const size_t BLOCKSIZE = 16;
        const char PAD_CHARACTER = 0x81;
    public:
        BlockCipher(std::ifstream &keyFile);
        void encrypt(std::ifstream &inputFile, std::ofstream &outputFile);
        void decrypt(std::ifstream &inputFile, std::ofstream &outputFile);
    private:
        size_t findPaddingLength(const string &data) const;
        void encryptBlock(string &block, const string &key) const;
        void swapBytes(string &data, const string &key) const;
        void removePadding(string &data) const;
};

#endif