#include "client.h"

Client::Client(const char *address, const char *port, Socket &skt) :
    address(address), port(port), skt(skt) {}

void Client::connect() {
    this->skt.start(this->address, this->port);
}

int Client::send(char *buffer, size_t size) {
    return this->skt._send(buffer, size);
}

int Client::receive(std::string &buffer, size_t size) {
    char buf[64];
    memset(buf, 0, 64);
    int bytesReceived = this->skt.receive(buf, size);
    for (int i = 0; i < bytesReceived; ++i) {
        buffer+=buf[i];
    }
    return bytesReceived;
}

void Client::shutdown() {
    this->skt._shutdown();
}

void Client::close() {
    this->skt._close();
}

Client::~Client() {
}
