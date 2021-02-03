#include "BlockCipher.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

BlockCipher::BlockCipher(const ifstream &keyFile): keyFile(keyFile) {}

void BlockCipher::encrypt(const ifstream &inputFile, ofstream &outputFile) {
    stringstream ss;
    ss << inputFile.rdbuf();
    cout << ss.str();

    // read a block at a time, padding when needed.

}

void BlockCipher::decrypt(const ifstream &inputFile, ofstream &outputFile) {

}