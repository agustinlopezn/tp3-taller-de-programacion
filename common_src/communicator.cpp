

#include "communicator.h"

#define BLOCK_SIZE 64

Communicator::Communicator() {
}

int Communicator::send(std::string &buffer, Socket &skt) {
    return skt._send(buffer.c_str(), buffer.size());
}

std::string Communicator::receive(Socket &skt) {
    std::string message = "";
    char buf[BLOCK_SIZE];
    int bytesReceived = skt.receive(buf, BLOCK_SIZE);
    message.append(buf, bytesReceived);
    return message;
}

Communicator::~Communicator() {
}
