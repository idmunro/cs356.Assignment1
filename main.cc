#include <iostream> // cout
#include <fstream> // ifstream
#include <stdexcept> // runtime_error
#include <string> // strings

using namespace std;

enum ArgType { CipherType, FileName, OutputFile, KeyFile, ModeOp };

int main( int argc, char *argv[] ) {
    if( argc != 5 ) printUsage(argv[0]);

    string cipherType = validateArgument<string>(argv[1], CipherType);
    ifstream inputFile = validateArgument<ifstream>(argv[2], FileName);
    ofstream outputFile = validateArgument<ofstream>(argv[3], OutputFile);
    ifstream keyFile = validateArgument<ifstream>(argv[4], KeyFile);
    string modeOp = validateArgument<string>(argv[5], ModeOp);

    

}

void blockEncrypt() {

}
void blockDecrupt() {

}

void streamEncrypt() {

}
void streamDecrypt() {
    
}

template <typename T>
T validateArgument( const char* arg, const ArgType argType ) {
    string argument(arg);

    switch(argType) {

        case CipherType:
            if(argument != "B" || argument != "S")
                throw runtime_error("Cipher Type must be either \"B\" for Block Cipher or \"S\" for Stream Cipher.\n");
            return argument;

        case FileName:
            ifstream inputFile(argument);
            if( !inputFile ) {
                throw runtime_error("Input File does not exist.");
            }
            return inputFile;
            break;

        case OutputFile:
            ofstream outputFile(argument);
            return outputFile;
            break;

        case KeyFile:
            ifstream keyFile(arguement);
            if( !inputFile ) {
                throw runtime_error("Key File does not exist.");
            }
            return keyFile;
            break;

        case ModeOp:
            if(argument != "E" || argument != "D")
                throw runtime_error("Mode Of Operation must be either \"E\" for Encrypt or \"D\" for Decrypt.\n");
            return argument;
            break;

    }
}

void printUsage(char* programName) {
    throw runtime_error("[USAGE] " + string(programName)  + 
                    " [CipherType: B or S] [InputFileName] [OutputFileName] [KeyFile] [ModeOfOperation: E or D]\n");
}



