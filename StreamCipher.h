#ifndef STREAMCIPHER_H
#define STREAMCIPHER_H

#include "Cipher.h"

class StreamCipher : public Cipher {
        const std::string key;
    public:
        StreamCipher(const std::string &keyFileName);
        void encrypt(const std::string &inputFileName, const std::string &outputFileName) const;
        void decrypt(const std::string &inputFileName, const std::string &outputFileName) const;
};

#endif