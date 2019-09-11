// crypt.h
// Header file for all of my cryptographic functions.
#ifndef CRYPT_H
#define CRYPT_H
#include <iostream>
class Crypt {
    private:
      std::string password; //Asked for during construction
      std::string text; //Passed into constructor
      std::string key;
      void authenticate(); // Called on by decrypt. May need to take an input. Not sure yet
      std::string HMAC; //Empty when
    
    public:
      Crypt(std::string text1);
      void encrypt();
      void decrypt();
      std::string getText();
      void printKey();
      void printPassword();
}; //Crypt
#endif
