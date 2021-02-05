#include "StreamCipher.h"

using std::ifstream;
using std::ofstream;
using std::string;

StreamCipher::StreamCipher(const string &keyFileName): key(extractKey(keyFileName)) {}

void StreamCipher::encrypt(const std::string &inputFileName, const std::string &outputFileName) const{
    ifstream inputFile = openInputFile(inputFileName);
    ofstream outputFile = openOutputFile(outputFileName);
    string data = fileToString(inputFile);

    size_t keyIndex = 0;
    for(char &c: data) {
        c ^= key[keyIndex];
        outputFile.put(c);
        keyIndex = (keyIndex + 1) % key.size();
    }
}

void StreamCipher::decrypt(const std::string &inputFileName, const std::string &outputFileName) const{
    encrypt(inputFileName, outputFileName);
}