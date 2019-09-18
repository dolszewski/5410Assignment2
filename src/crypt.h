// crypt.h
// Header file for all of my cryptographic functions.
#ifndef CRYPT_H
#define CRYPT_H
#include <iostream>
#include <openssl/evp.h>
#include <openssl/crypto.h>
#include <openssl/sha.h>
#include <openssl/aes.h>

class Crypt {
    private:
      std::string password;
      std::string text;
      std::string ctext;
      unsigned char key[64];
      void authenticate();
      unsigned char hash[64];
      void generateKey();
    void generateHash(int flag);
    
    public:
      Crypt(std::string text1);
      void encrypt();
      void decrypt();
      std::string getText();
      void printKey();
      void printPassword();
      std::string getCipherText();
      void fixText();

    
}; //Crypt
#endif
