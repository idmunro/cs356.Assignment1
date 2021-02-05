#include "BlockCipher.h"
#include "StreamCipher.h"

#include <fstream> // ifstream
#include <stdexcept> // runtime_error
#include <string> // strings
#include <memory> // unique_ptr

using std::string;
using std::ifstream;
using std::ofstream;
using std::unique_ptr;
using std::runtime_error;

Cipher* getCipher(const string &cipherType, const string &keyFileName) {
    if(cipherType == "B") {
        return new BlockCipher(keyFileName);
    }
    else if(cipherType == "S") {
        return new StreamCipher(keyFileName);
    }
    else {
        throw runtime_error("Cipher Type must be either \"B\" for Block Cipher or \"S\" for Stream Cipher.\n"
                            "You Entered: " + cipherType + '\n');
    }
}

const string &validateModeOp(const string &modeOp) {
    if(modeOp != "E" && modeOp != "D") {
        throw runtime_error("Mode Of Operation must be either \"E\" for Encrypt or \"D\" for Decrypt. "
                    "You Entered: " + modeOp + '\n');
    }
    return modeOp;
}

void printUsage(const string &programName) {
    throw runtime_error("[USAGE] " + programName + 
                    " [CipherType: B or S] [InputFileName] [OutputFileName] [KeyFile] [ModeOfOperation: E or D]\n");
}

int main( int argc, char *argv[] ) {
    if( argc != 6 ) printUsage(argv[0]);

    const string cipherType(argv[1]);
    const string inputFileName(argv[2]);
    const string outputFileName(argv[3]);
    const string keyFileName(argv[4]);
    const string modeOp(validateModeOp(argv[5]));

    unique_ptr<Cipher> cipher(getCipher(cipherType, keyFileName));

    modeOp == "E" ? cipher->encrypt(inputFileName, outputFileName) 
                  : cipher->decrypt(inputFileName, outputFileName);
}
