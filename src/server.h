//server.h
//Header file for server.cpp. This creates the server for gsend.

#ifndef SERVER_H
#define SERVER_H

#include <iostream>

#include "lib/PracticalSocket/PracticalSocket.h"
#include "lib/PracticalSocket/common.h"

class Server {
    private:
        std::string info;
    public:
        Server(unsigned short PORT_NUMBER);
        std::string getInformation();
};

#endif
