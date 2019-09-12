#include "crypt.h"

#include <iostream>
#include <openssl/evp.h>
#include <openssl/crypto.h>
#include <openssl/sha.h>

Crypt::Crypt(std::string text1) : text(text1) {
    std::cout << "password?" << std::endl;
    std::cin >> password;
    std::cout << "thank you!" << std::endl;
    generateKey();
    
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

void Crypt::generateKey() {
    
    int keylength = 16;
    char hexResult[2*keylength+1];
    const unsigned char salt[] = "KCl";
    int iter = 4096;
    int success = PKCS5_PBKDF2_HMAC (password.c_str(), sizeof(password)-1, salt, sizeof(salt)-1, iter, EVP_sha512(), keylength, key);
    for (int i = 0; i < sizeof(key); i++){
        sprintf(hexResult + (i * 2), "%02x ", 255 & key[i]);
    }
    printf("%s\n", hexResult);

}
