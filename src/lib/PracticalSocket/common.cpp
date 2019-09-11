#include "common.h"

void sendInt(CommunicatingSocket *sock, uint32_t val) throw(SocketException) {
    val = htonl(val);
    sock->send(&val, sizeof(val));
}

void sendString(CommunicatingSocket *sock, const std::string &str) throw(SocketException) {
    sendInt(sock, str.length());
    sock->send(str.c_str(), str.length());
}

uint32_t recvInt(CommunicatingSocket *sock) throw (std::runtime_error) {
    uint32_t val;
    if (sock->recvFully(&val, sizeof(val))!= sizeof(val)) {
        throw runtime_error("Socket closed during transfer of int");
    }
    return ntohl(val);
}

std::string recvString(CommunicatingSocket *sock) throw(runtime_error) {
    uint32_t len = recvInt(sock);
    char *buffer = new char [len+1];
    if (sock->recvFully(buffer, len)!= len) {
        delete [] buffer;
        throw runtime_error("Socket closed during read of string");
    }
    buffer[len] = '\0';
    std::string result(buffer);
    delete [] buffer;
    return result;
}

