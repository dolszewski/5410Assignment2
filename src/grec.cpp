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
        Crypt myDecryption(argv[1]);
        myDecryption.decrypt();
        data.filenameSubtract();
        data.write(myDecryption.getText());
    } else if (argc == 4 && (string) argv[2] == "-d"){
        
    } else {
        cerr << "Incorrect arguments" << endl;
        exit(3);
    }
    
    return 0;
} // main

