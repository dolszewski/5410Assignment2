#include server.h

Server::Server(in_port_t PORT_NUMBER) {
    
    try {
        TCPServerSocket servSock(PORT_NUMBER);
        
        for( ; ; ){
            TCPSocket *sock = servSock.accept();
            this->info = recvString(sock);
        }
        
    } catch (SocketException &e) {
        std::cerr << e.what() << std::endl;
    }
    delete sock;
    
}

std::string Server::getInformation() {
    return  info;
}
