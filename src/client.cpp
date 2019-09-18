#include <iostream>


#include "client.h"
#include "lib/PracticalSocket/common.h"

Client::Client(const char * address, unsigned short PORT_NUMBER, std::string information) {
    try {
        
        TCPSocket sock(address, PORT_NUMBER);
        sendString(&sock, information);
                
        //add in success and exit mode
    } catch(runtime_error &e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

