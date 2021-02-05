#include "Cipher.h"

using std::string;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::runtime_error;
using std::ios_base;

string Cipher::fileToString(ifstream &file) const{
    stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

string Cipher::extractKey(const string &keyFileName) {
    ifstream keyFile = openKeyFile(keyFileName);
    string key = fileToString(keyFile);
    return key;
}

ifstream Cipher::openInputFile(const string &fileName) const{
    string argument(fileName);

    ifstream inputFile(argument, ios_base::binary);
    if( !inputFile ) {
        throw runtime_error("Input File does not exist. File name provided: " + argument + '\n');
    }
    return inputFile;
}

ifstream Cipher::openKeyFile(const string &fileName) const{
    string argument(fileName);

    ifstream keyFile(argument, ios_base::binary);
    if( !keyFile ) {
        throw runtime_error("Key File does not exist. File name provided: " + argument + '\n');
    }
    return keyFile;
}

ofstream Cipher::openOutputFile(const string&fileName) const{
    string argument(fileName);

    ofstream outputFile(argument, ios_base::binary);
    return outputFile;
}

