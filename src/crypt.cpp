#include "crypt.h"

#include <iostream>

Crypt::Crypt(std::string text1) : text(text1) {
    std::cout << "password?" << std::endl;
    std::cin >> password;
    std::cout << "thank you!" << std::endl;
    //Need to add key generator and HMAC;
}

void Crypt::authenticate() {
    return;
}
void Crypt::encrypt() {
    return;
}
void Crypt::decrypt() {
    return;
}
std::string Crypt::getText() {
    return text;
}
void Crypt::printKey() {
    std::cout << "Key:" << key << std::endl;
    return;
}
void Crypt::printPassword() {
    std::cout <<"Password:"<< password << std::endl;
    return;
}
