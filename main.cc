#include "ArgValidator.h"
#include "BlockCipher.h"
#include "StreamCipher.h"

#include <iostream> // cout
#include <fstream> // ifstream
#include <stdexcept> // runtime_error
#include <string> // strings
#include <memory> // unique_ptr

Cipher* getCipher(const string &cipherType, const ifstream &keyFile);
void printUsage(char* programName);

using namespace std;


int main( int argc, char *argv[] ) {
    if( argc != 6 ) printUsage(argv[0]);

    string cipherType = validateArgument<CipherType>(argv[1]);
    ifstream inputFile = validateArgument<InputFile>(argv[2]);
    ofstream outputFile = validateArgument<OutputFile>(argv[3]);
    string modeOp = validateArgument<ModeOp>(argv[5]);
    ifstream keyFile = validateArgument<KeyFile>(argv[4]);

    unique_ptr<Cipher> cipher(getCipher(cipherType, keyFile));

    if(modeOp == "E") {
        cipher -> encrypt(inputFile, outputFile);
    }
    else {
        cipher -> decrypt(inputFile, outputFile);
    }
}

Cipher* getCipher(const string &cipherType, const ifstream &keyFile) {
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

