#include "ArgValidator.h"

#include <iostream> // cout
#include <fstream> // ifstream
#include <stdexcept> // runtime_error
#include <string> // strings

using namespace std;
using namespace ArgValidator;


int main( int argc, char *argv[] ) {
    if( argc != 5 ) printUsage(argv[0]);

    string cipherType = validateArgument<string>(argv[1], CipherType);
    ifstream inputFile = validateArgument<ifstream>(argv[2], FileName);
    ofstream outputFile = validateArgument<ofstream>(argv[3], OutputFile);
    ifstream keyFile = validateArgument<ifstream>(argv[4], KeyFile);
    string modeOp = validateArgument<string>(argv[5], ModeOp);

    if(modeOp == "E") {
        if(cipherType == "B") {
            blockEncrypt();
        }
        else {
            streamEncrypt();
        }
    }
    else {
        if(cipherType == "B") {
            blockDecrypt();
        }
        else {
            streamDecrypt();
        }
    }

}

void blockEncrypt() {

}
void blockDecrypt() {

}

void streamEncrypt() {

}
void streamDecrypt() {

}

void printUsage(char* programName) {
    throw runtime_error("[USAGE] " + string(programName)  + 
                    " [CipherType: B or S] [InputFileName] [OutputFileName] [KeyFile] [ModeOfOperation: E or D]\n");
}



