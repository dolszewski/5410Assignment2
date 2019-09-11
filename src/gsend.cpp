#include <iostream>
#include <stdio.h>

#include "filehandler.h"
#include "crypt.h"
#include "client.h"
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        cerr << "Incorrect number of arguments" << endl;
        exit(3);
    }
    if (argc == 3 && (string) argv[2] == "-l"){
        Filehandler data(argv[1]);
        Crypt myEncryption(data.read());
        myEncryption.encrypt();
        data.filenameAdd();
        data.write(myEncryption.getText());
    } else if (argc == 4 && (string) argv[2] == "-d"){
        
    } else {
        cerr << "Incorrect arguments" << endl;
        exit(3);
    }
    cout << "Program complete" << endl;
    return 0;
} // main
