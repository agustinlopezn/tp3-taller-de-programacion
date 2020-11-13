#include "client.h"

#define BUFF_SIZE 64

Client::Client(const char *address, const char *port) :
    address(address), port(port), skt(false) {}


int Client::receive(std::string &buffer, size_t size) {
    char buf[BUFF_SIZE];
    memset(buf, 0, BUFF_SIZE);
    int bytesReceived = this->skt.receive(buf, size);
    for (int i = 0; i < bytesReceived; ++i) {
        buffer+=buf[i];
    }
    return bytesReceived;
}

void Client::start() {
    Reader reader;
    std::string buff;
    char buffAux[BUFF_SIZE];
    this->skt.start(this->address, this->port);
    while (!reader.finished()) {
        size_t size = reader.read(buffAux, BUFF_SIZE);
        if (size < 1) break;
        buff += buffAux;
        communicator.send(buff, &this->skt);
        buff.clear();
    }
    // this->shutdown();
    std::string buffer;
    while (receive(buffer, BUFF_SIZE) > 0) {  // CHANGE
        std::cout << buffer;
        buffer.clear();
    }
}

void Client::shutdown() {
    this->skt._shutdown();
}

void Client::close() {
    this->skt._close();
}

Client::~Client() {
    this->close();
}
