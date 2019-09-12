#ifndef SERVER_H
#define SERVER_H

#include <iostream>

#include "lib/PracticalSocket/PracticalSocket.h"
#include "lib/PracticalSocket/common.h"

class Client {
    public:
      Client(const char * address, unsigned short PORT_NUMBER, std::string information);
};

#endif
