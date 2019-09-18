#include "crypt.h"

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <openssl/evp.h>
#include <openssl/crypto.h>
#include <openssl/sha.h>
#include <openssl/aes.h>
#include <openssl/hmac.h>

Crypt::Crypt(std::string text1) : text(text1) {
    std::cout << "password:" << std::endl;
    std::cin >> password;
    generateKey();
    
    //Need to add key generator and HMAC;
}
void Crypt::generateHash(int flag) {
    
    if(flag ==0) {
        unsigned char* digest = HMAC(EVP_sha512(), key, 64, (unsigned char*)ctext.c_str(), ctext.length(), NULL, NULL);
        printf("\nHash: ");
        for (int i = 0; i < 64; i++){
            hash[i] = digest[i];
            printf("%02X ", hash[i]);

        }
        //digest = HMAC(EVP_sha512(), key, 64, (unsigned char*)text.c_str(), text.length(), NULL, NULL);
        std::string result;
        for (int i =0; i < 64 ; i++) {
            result.push_back(hash[i]);
        }
        std::string delim = "a111111";
        ctext = ctext + delim;
        ctext = ctext + result;
     
    } else {
        
        unsigned char* digest = HMAC(EVP_sha512(), key, 64, (unsigned char*)text.c_str(), text.length()-1, NULL, NULL);
/*
        printf("\nNew Hash: ");
        for (int i = 0; i < 64; i++){
         
                printf("%02X ", digest[i]);
            
        }
        printf("\nOld Hash: ");
        for (int i = 0; i < 64; i++){
            
            printf("%02X ", hash[i]);
            
        }
 */
        for (int i = 0; i < 64; i++){
            if (hash[i]!= digest[i]){
                std::cerr << "\nHMAC doesn't match" << std::endl;
                exit(63);
            }
        }
        
    }

    return;
}
void Crypt::authenticate() {
    generateHash(1);
    
    return;
}
void Crypt::encrypt() {
    unsigned char keyAES[32];
    unsigned char iv[16];
    std::string ctext_temp;
    ctext_temp.resize(text.size()+16);
    int temp = (int) text.size();
    
    for (int i = 0; i < 32; i++) {
        keyAES[i] = key[i];
        if (i < 16) {
            iv[i] = key[i+32];
        }
    }
    EVP_CIPHER_CTX ctx;
    int rc = EVP_EncryptInit(&ctx, EVP_aes_256_cbc(), keyAES, iv);
    if (rc!=1) {
        throw std::runtime_error("EVP_EncryptINIT_ex failed");
    }
    
    EVP_EncryptUpdate(&ctx, (unsigned char*)&ctext_temp[0], &temp, (unsigned char*)&text[0], (int)text.size() );
    int temp2 = (int) ctext_temp.size() - temp;
    EVP_EncryptFinal(&ctx, (unsigned char*)&ctext_temp[0] + temp, &temp2);
    ctext_temp.resize(temp+temp2);
    ctext = ctext_temp;
    generateHash(0);

    return;
}
void Crypt::decrypt() {
    unsigned char keyAES[32];
    unsigned char iv[16];
    std::string delim = "a111111";
    std::size_t pos = text.find(delim);
    std::string readHash = text.substr(pos+delim.length());
    
    text = text.erase(pos+1);
    for(int i = 0; i < 64; i++) {
        hash[i] = readHash[i];
    }
    
    authenticate();
    std::string ctext_temp;
    ctext_temp.resize(text.size());
    int temp = (int) text.size();
    for (int i = 0; i < 32; i++) {
        keyAES[i] = key[i];
        if (i < 16) {
            iv[i] = key[i+32];
        }
    }
    EVP_CIPHER_CTX ctx;
    int rc = EVP_DecryptInit(&ctx, EVP_aes_256_cbc(),  keyAES, iv);
    if (rc!=1) {
        throw std::runtime_error("EVP_DecryptINIT_ex failed");
    }
    
    EVP_DecryptUpdate(&ctx, (unsigned char*)&ctext_temp[0], &temp, (unsigned char*)&text[0], (int)text.size());
    int temp2 = (int) ctext_temp.size() - temp;
    EVP_DecryptFinal(&ctx, (unsigned char*)&ctext_temp[0] + temp-16, &temp2);
    //ctext=reinterpret_cast<char*>(ctext_temp);
    ctext_temp.resize(temp+temp2);

    ctext = ctext_temp;

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
    
    int keylength = 64;
    char hexResult[3*keylength+1];
    const unsigned char salt[] = "KCl";
    
    int iter = 4096;
    int success = PKCS5_PBKDF2_HMAC (password.c_str(), -1, salt, 3, iter, EVP_sha512(), keylength, key);
    printf("\nKey: ");
    for (int i = 0; i < sizeof(key); i++){
        printf("%02X ", key[i]);
    }

}
std::string Crypt::getCipherText() {

    return ctext;
}

void Crypt::fixText() {
    int i = (int)ctext.size();
    int a = (int) ctext[i-1];
    std::cout << "\n Fix code: " << a << std::endl;
    if(a < 32 && a>0) ctext = ctext.substr(0, i-a);

}
