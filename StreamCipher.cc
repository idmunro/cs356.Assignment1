#include "StreamCipher.h"
#include <iostream>

using std::ifstream;
using std::ofstream;
using std::string;

StreamCipher::StreamCipher(ifstream &keyFile) : keyFile(keyFile) {}

// Change to read through character by character to reduce memory size
void StreamCipher::encrypt(ifstream &inputFile, ofstream &outputFile) {
    string key = fileToString(keyFile);
    string data = fileToString(inputFile);

    size_t keyIndex = 0;
    for(char &c: data) {
        c ^= key[keyIndex];
        outputFile.put(c);
        keyIndex = (keyIndex + 1) % key.size();
    }
}

void StreamCipher::decrypt(ifstream &inputFile, ofstream &outputFile) {
    encrypt(inputFile, outputFile);
}