
#include "Cipher.h"

#include <fstream>
#include <string>

Cipher::Cipher(const string &cipherType, const string &key) {
    if(cipherType == "B") {
        cipher = new BlockCipher(key);
    }
    else {
        cipher = new StreamCipher(key);
    }
}