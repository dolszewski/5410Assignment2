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
        data.write(myDecryption.getText());
    } else if (argc == 4 && (string) argv[2] == "-d"){
        std::string portN = argv[3];
        unsigned short portNumber = (unsigned short) std::stoul(portN, NULL, 0);
        Server server(portNumber);
        Crypt myDecryption(server.getInformation());
        myDecryption.decrypt();
        std::cout << myDecryption.getText() << std::endl;
        Filehandler data(argv[1]);
        data.write(myDecryption.getText());
    } else {
        cerr << "Incorrect arguments" << endl;
        exit(3);
    }
    
    return 0;
} // main

