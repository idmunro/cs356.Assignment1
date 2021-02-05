#include "Cipher.h"
#include <sstream> // stringstream

using std::string;
using std::stringstream;
using std::ifstream;

string Cipher::fileToString(ifstream &file) {
    stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}