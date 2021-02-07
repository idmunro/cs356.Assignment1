#include "BlockCipher.h"

using std::ifstream;
using std::ofstream;
using std::string;
using std::swap;

BlockCipher::BlockCipher(const string &keyFileName): key(extractKey(keyFileName)){}

void BlockCipher::encrypt(const std::string &inputFileName, const std::string &outputFileName) const{
    ifstream inputFile = openInputFile(inputFileName);
    ofstream outputFile = openOutputFile(outputFileName);
    string data = fileToString(inputFile);
    if(!data.size()) return;

    addPadding(data);
    encryptData(data, key);
    swapBytes(data, key);

    outputFile.write(data.c_str(), data.size());
}

void BlockCipher::decrypt(const std::string &inputFileName, const std::string &outputFileName) const{
    ifstream inputFile = openInputFile(inputFileName);
    ofstream outputFile = openOutputFile(outputFileName);
    string data = fileToString(inputFile);
    if(!data.size()) return;
    
    swapBytes(data, key);
    encryptData(data, key);
    removePadding(data);
    
    outputFile.write(data.c_str(), data.size());
}

void BlockCipher::addPadding(string &data) const{
    size_t padLength = findPaddingLength(data);
    data.insert(data.size(), padLength, PAD_CHARACTER);
}

void BlockCipher::encryptData(string &data, const string &key) const{
    for(size_t i = 0; i < data.size(); i += BLOCKSIZE) {
        string block = data.substr(i, BLOCKSIZE);
        encryptBlock(block, key);
        data.replace(i, BLOCKSIZE, block, 0, BLOCKSIZE);
    }
}

void BlockCipher::swapBytes(string &data, const string &key) const{
    for(size_t f = 0, r = data.size()-1; f < r; ++f) {
        if(key[f % key.size()] % 2) {
            swap(data[f], data[r]);
            --r;
        }
    }
}

void BlockCipher::removePadding(string &data) const{
    size_t index = data.size()-1;
    char currentChar = data[index];

    while(currentChar == PAD_CHARACTER) {
        --index;
        currentChar = data[index];
    }

    size_t padLength = data.size() - index + 1;
    data.erase(data.end()-padLength + 1, data.end());
}

void BlockCipher::encryptBlock(string &block, const string &key) const{
    for(size_t i = 0; i < BLOCKSIZE; ++i) {
        block[i] ^= key[i];
    }
}

size_t BlockCipher::findPaddingLength(const string &data) const{
    return (data.size() % BLOCKSIZE) ? (BLOCKSIZE - (data.size() % BLOCKSIZE)) : 0;
}
