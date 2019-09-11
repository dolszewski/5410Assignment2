//common.h
// Header file for common.cpp. This contains a list of functions that both the server.cpp and client.cpp will be using.
#ifndef COMMON_H
#define COMMON_H

#include "PracticalSocket.h"
#include <string>
#include <vector>

void sendInt(CommunicatingSocket *sock, uint32_t val) throw(SocketException);

void sendString(CommunicatingSocket *sock, const std::string &str) throw(SocketException);

uint32_t recvInt(CommunicatingSocket *sock) throw(std::runtime_error);

std::string recvString(CommunicatingSocket *sock) throw(std::runtime_error);

#endif
