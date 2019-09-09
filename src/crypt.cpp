#include "crypt.h"

#include <iostream>

Crypt::Crypt(std::string text1) : text(text1) {
    std::cout << "password?";
    std::cin >> password;
    std::cout << "\nthank you\n!";
}

void Crypt::authenticate() {
    
}
std::string Crypt::encrypt() {
    return NULL;
}
std::string Crypt::decrypt() {
    return NULL;
}
