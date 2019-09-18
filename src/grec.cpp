#include <iostream>
#include <stdio.h>

#include "filehandler.h"
#include "crypt.h"
#include "server.h"


using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        cerr << "Incorrect number of arguments" << endl;
        exit(3);
    }
    if (argc == 3 && (string) argv[2] == "-l"){
        Filehandler data(argv[1]);
        Crypt myDecryption(data.read());
        myDecryption.decrypt();
        data.filenameSubtract();
        myDecryption.fixText();
        data.write(myDecryption.getCipherText());
    } else if (argc == 4 && (string) argv[2] == "-d"){
        std::string portN = argv[3];
        unsigned short portNumber = (unsigned short) std::stoul(portN, NULL, 0);
        Server server(portNumber);
        Crypt myDecryption(server.getInformation());
        myDecryption.decrypt();
        std::cout << myDecryption.getCipherText() << std::endl;
        Filehandler data(argv[1]);
        myDecryption.fixText();
        data.write(myDecryption.getCipherText());
    } else {
        cerr << "Incorrect arguments" << endl;
        exit(3);
    }
    
    return 0;
} // main

