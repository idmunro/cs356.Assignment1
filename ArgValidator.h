#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <stdexcept>
#include <iostream>
#include <ifstream>

enum ArgType { CipherType, FileName, OutputFile, KeyFile, ModeOp };

class ArgValidator {
public:

template <typename T>
    static T validateArgument(const char* arg, ArgType argType) {
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

private:

    ifstream validateIfstream(ArgType argType) {

    }

    ofstream validateOfstream(ArgType argType) {

    }

    string validateModeOp() {

    }
    string validateCipherType() {

    }

}


#endif