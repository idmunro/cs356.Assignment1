CC=g++
CFLAGS= -std=c++17 -Wall -pedantic -Wfatal-errors -Wextra -O2

cipher: main.o Cipher.o BlockCipher.o StreamCipher.o
	$(CC) $(CFLAGS) main.o Cipher.o BlockCipher.o StreamCipher.o -o cipher

main.o: main.cc
	$(CC) $(CFLAGS) -c main.cc

Cipher.o: Cipher.cc Cipher.h
	$(CC) $(CFLAGS) -c Cipher.cc

BlockCipher.o: BlockCipher.cc BlockCipher.h
	$(CC) $(CFLAGS) -c BlockCipher.cc

StreamCipher.o: StreamCipher.cc StreamCipher.h
	$(CC) $(CFLAGS) -c StreamCipher.cc

clean:
	rm *.o cipher