

#include "communicator.h"

#define BLOCK_SIZE 64

Communicator::Communicator() {
}

int Communicator::send(std::string &buffer, Socket *skt) {
    return 0;
    //return skt->_send(buffer.c_str(), buffer.size());
}

std::string Communicator::receive(Socket *skt) {
    std::string message = "";
    char buf[BLOCK_SIZE];
    memset(buf, 0, BLOCK_SIZE);
    int bytesReceived = skt->receive(buf, BLOCK_SIZE);
    for (int i = 0; i < bytesReceived; ++i) {
        message += buf[i];
    }
    return message;
}   
Communicator::~Communicator() {
}
