#include <iostream>
#include <stdio.h>

#include "filehandler.h"
#include "crypt.h"
#include "client.h"
using namespace std;

struct Address {
    std::string host;
    unsigned short port;
};
Address parseAddress(char* argv[]) {
    Address addr;
    std::string name = argv[3];
    int pos = name.find(':');
    if (pos != std::string::npos) {
        addr.host = name.substr(0,pos);
        std::string portN = name.substr(pos+1);
        addr.port = (unsigned short) std::stoul(portN, NULL, 0);
        
    } else {
        std::cerr << "Unable to parse port." << std::endl;
        exit(1);
    }

    return addr;
}
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
        Address addrServer = parseAddress(argv);
        Filehandler data(argv[1]);
        Crypt myEncryption(data.read());
        myEncryption.encrypt();
        Client client(addrServer.host.c_str(), addrServer.port, myEncryption.getText());
    
    } else {
        cerr << "Incorrect arguments" << endl;
        exit(3);
    }
    cout << "Program complete" << endl;
    return 0;
} // main



