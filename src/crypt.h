// crypt.h
// Header file for all of my cryptographic functions.
#ifndef CRYPT_H
#define CRYPT_H
#include <iostream>
class Crypt {
    private:
      std::string password; //Asked for during construction
      std::string text; //Passed into constructor
      void authenticate(); // Called on by decrypt. May need to take an input. Not sure yet
    public:
      Crypt(std::string text1);
      std::string encrypt();
      std::string decrypt();
      
}; //Crypt
#endif
