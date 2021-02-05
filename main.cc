#include "ArgValidator.h"
#include "BlockCipher.h"
#include "StreamCipher.h"

#include <iostream> // cout
#include <fstream> // ifstream
#include <stdexcept> // runtime_error
#include <string> // strings
#include <memory> // unique_ptr

Cipher* getCipher(const string &cipherType, ifstream &keyFile);
void printUsage(char* programName);

using namespace std;

int main( int argc, char *argv[] ) {
    if( argc != 6 ) printUsage(argv[0]);

    // Do file validation in Cipher class
    // Do cipherType and modeOp here in main
    string cipherType = validateArgument<CipherType>(argv[1]);
    ifstream inputFile = validateArgument<InputFile>(argv[2]);
    ofstream outputFile = validateArgument<OutputFile>(argv[3]);
    ifstream keyFile = validateArgument<KeyFile>(argv[4]);
    string modeOp = validateArgument<ModeOp>(argv[5]);

    unique_ptr<Cipher> cipher(getCipher(cipherType, keyFile));

    modeOp == "E" ? cipher->encrypt(inputFile, outputFile) 
                  : cipher->decrypt(inputFile, outputFile);

    inputFile.close();
    outputFile.close();
    keyFile.close();
}

Cipher* getCipher(const string &cipherType, ifstream &keyFile) {
    if(cipherType == "B") {
        return new BlockCipher(keyFile);
    }
    else {
        return new StreamCipher(keyFile);
    }
}

void printUsage(char* programName) {
    throw runtime_error("[USAGE] " + string(programName)  + 
                    " [CipherType: B or S] [InputFileName] [OutputFileName] [KeyFile] [ModeOfOperation: E or D]\n");
}

