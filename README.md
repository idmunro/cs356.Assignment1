# cs356.Assignment1

## Purpose
This assignment provides an example of basic encryption methods. The algorithms are simple and not very effective but this was meant to be a learning experience on encryption. I tried to set up the structure of the project so that I could easily build on these techniques using this existing code as a foundation.

### Cipher Class
This is an abstract class that provides implementation of file management and util operations.
### StreamCipher Class
This class implements the `Cipher` class methods `encrypt` and `decrypt` by using a stream-encryption method.
Each byte is run sequentially through the algorithm where each byte is XORed with a corresponding byte of the key provided.
### BlockCipher Class
This class implements the `Cipher` class methods `encrypt` and `decrypt` by using a block-encryption method.
Each 128-bit block is XORed using a 128-bit key block and then reorganized based on values in the key provided.

## How to compile and run
1. Run `Make` which will produce the executable called `cipher`
2. `./cipher [type] [inputfile] [outputfile] [keyfile] [modeOp]`
