#include "server.h"

#include <iostream>

#include "lib/PracticalSocket/common.h"
Server::Server(unsigned short PORT_NUMBER) {
    
    try {
        TCPServerSocket servSock(PORT_NUMBER);
        int a = 0;
        for( ; ; ){
            if (!info.empty()){
                break;
            }
            TCPSocket *sock = servSock.accept();
            this->info = recvString(sock);
            delete sock;
            

        }
        
    } catch (SocketException &e) {
        std::cerr << e.what() << std::endl;
    }
    
    
}

std::string Server::getInformation() {
    return  info;
}
