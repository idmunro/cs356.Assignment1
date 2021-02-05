#ifndef CIPHER_H
#define CIPHER_H

#include <fstream> // ifstream, ofstream
#include <string> // string
#include <stdexcept> // runtime_error
#include <sstream> // stringstream

class Cipher {
    public:
        virtual void encrypt(const std::string &inputFileName, const std::string &outputFileName) const = 0;
        virtual void decrypt(const std::string &inputFileName, const std::string &outputFileName) const = 0;

    protected:
        std::string extractKey(const std::string &keyFileName);
        std::string fileToString(std::ifstream &file) const;
        std::ifstream openInputFile(const std::string &fileName) const;
        std::ifstream openKeyFile(const std::string &fileName) const;
        std::ofstream openOutputFile(const std::string&fileName) const;
};

#endif