#ifndef BLOCKCIPHER_H
#define BLOCKCIPHER_H

#include "Cipher.h"
#include <algorithm> // swap

class BlockCipher : public Cipher {
        const std::string key;
        const size_t BLOCKSIZE = 16;
        const char PAD_CHARACTER = static_cast<char>(0x81);
    public:
        BlockCipher(const std::string &keyFileName);
        void encrypt(const std::string &inputFileName, const std::string &outputFileName) const;
        void decrypt(const std::string &inputFileName, const std::string &outputFileName) const;
    private:
        size_t findPaddingLength(const std::string &data) const;
        void addPadding(std::string &data) const;
        void removePadding(std::string &data) const;
        void encryptData(std::string &block, const std::string &key) const;
        void encryptBlock(std::string &block, const std::string &key) const;
        void swapBytes(std::string &data, const std::string &key) const;
};

#endif