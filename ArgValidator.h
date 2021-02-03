#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>

enum ArgType { CipherType, InputFile, OutputFile, KeyFile, ModeOp };

using namespace std;

template <ArgType A>
auto validateArgument(const char* arg);

template <>
auto validateArgument<CipherType>(const char* arg) {
    string argument(arg);

    if(argument != "B" && argument != "S")
        throw runtime_error("Cipher Type must be either \"B\" for Block Cipher or \"S\" for Stream Cipher.\n"s
                            + "You Entered: "s + argument + "\n"s);

    return argument;
}

template <>
auto validateArgument<InputFile>(const char* arg) {
    string argument(arg);

    ifstream inputFile(argument, ios_base::binary);
    if( !inputFile ) {
        throw runtime_error("Input File does not exist.");
    }
    return inputFile;
}

template <>
auto validateArgument<OutputFile>(const char* arg) {
    string argument(arg);

    ofstream outputFile(argument, ios_base::binary);
    return outputFile;
}

template <>
auto validateArgument<KeyFile>(const char* arg) {
    string argument(arg);

    ifstream keyFile(argument, ios_base::binary);
    if( !keyFile ) {
        throw runtime_error("Key File does not exist.");
    }
    return keyFile;
}

template <>
auto validateArgument<ModeOp>(const char* arg) {
    string argument(arg);

    if(argument != "E" && argument != "D")
        throw runtime_error("Mode Of Operation must be either \"E\" for Encrypt or \"D\" for Decrypt.\n");
    return argument;
}

#endif