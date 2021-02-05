#include "BlockCipher.h"
#include <algorithm> // swap
#include <iostream> // cout

using std::ifstream;
using std::ofstream;
using std::string;
using std::swap;
using std::cout;
using std::endl;

BlockCipher::BlockCipher(ifstream &keyFile): keyFile(keyFile) {}

void BlockCipher::encrypt(ifstream &inputFile, ofstream &outputFile) {
    const string key = fileToString(keyFile);
    string data = fileToString(inputFile);
    
    size_t padLength = findPaddingLength(data);
    data.insert(data.size(), padLength, PAD_CHARACTER);

    for(size_t i = 0; i < data.size(); i += BLOCKSIZE) {
        string block = data.substr(i, BLOCKSIZE);
        encryptBlock(block, key);
        data.replace(i, BLOCKSIZE, block, 0, BLOCKSIZE);
    }

    swapBytes(data, key);
    outputFile.write(data.c_str(), data.size());
}

void BlockCipher::decrypt(ifstream &inputFile, ofstream &outputFile) {
    const string key = fileToString(keyFile);
    string data = fileToString(inputFile);
    swapBytes(data, key);

    for(size_t i = 0; i < data.size(); i += BLOCKSIZE) {
        string block = data.substr(i, BLOCKSIZE);
        encryptBlock(block, key);
        data.replace(i, BLOCKSIZE, block, 0, BLOCKSIZE);
    }

    removePadding(data);
    outputFile.write(data.c_str(), data.size());
}

void BlockCipher::swapBytes(string &data, const string &key) const{
    for(size_t f = 0, r = data.size()-1; f < r; ++f, --r) {
        if(key[f % key.size()] % 2) {
            swap(data[f], data[r]);
        }
    }
}

void BlockCipher::encryptBlock(string &block, const string &key) const{
    for(size_t i = 0; i < BLOCKSIZE; ++i) {
        block[i] ^= key[i];
    }
}

size_t BlockCipher::findPaddingLength(const string &data) const{
    return (data.size() % BLOCKSIZE) ? (BLOCKSIZE - (data.size() % BLOCKSIZE)) : 0;
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

