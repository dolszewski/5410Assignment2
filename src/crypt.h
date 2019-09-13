// crypt.h
// Header file for all of my cryptographic functions.
#ifndef CRYPT_H
#define CRYPT_H
#include <iostream>
#include <openssl/evp.h>
#include <openssl/crypto.h>
#include <openssl/sha.h>

class Crypt {
    private:
      std::string password; //Asked for during construction
      std::string text; //Passed into constructor
      unsigned char key[64];
      void authenticate(); // Called on by decrypt. May need to take an input. Not sure yet
      std::string HMAC; //Empty when
      void generateKey();
    
    public:
      Crypt(std::string text1);
      void encrypt();
      void decrypt();
      std::string getText();
      void printKey();
      void printPassword();

    
}; //Crypt
#endif
