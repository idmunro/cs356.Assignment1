#include "StreamCipher.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

StreamCipher::StreamCipher(const ifstream &keyFile) : keyFile(keyFile) {}

void StreamCipher::encrypt(const ifstream &inputFile, ofstream &outputFile) {
    stringstream ss;
    ss << inputFile.rdbuf();
    
    // read an 8 bit char at a time. might want to break ss into char array
}

void StreamCipher::decrypt(const ifstream &inputFile, ofstream &outputFile) {

}