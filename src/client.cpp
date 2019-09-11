#include "client.h"

Client::Client(char * address, in_port_t PORT_NUMBER, std::string information) {
    try {
        TCPSocket sock(address, PORT_NUMBER);
        sendString(information);
    } catch(runtime_error &e) {
        std::cerr << e.what() << endl;
        exit(1);
    }
}

