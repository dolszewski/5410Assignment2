#ifndef SERVER_H
#define SERVER_H

#include "lib/PracticalSocket/PracticalSocket.h"
#include "lib/PracticalSocket/common.h"

class Client {
    public:
      Client(char * address, in_port_t PORT_NUMBER, std::string information);
};

#endif
