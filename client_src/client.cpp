#include "client.h"

#define BUFF_SIZE 64

Client::Client(const char *address, const char *port) :
    address(address), port(port), skt(address, port, false) {}

void Client::start() {
    Reader reader;
    std::string buff;
    char buffAux[BUFF_SIZE];
    while (!reader.finished()) {
        size_t size = reader.read(buffAux, BUFF_SIZE);
        if (size < 1) break;
        buff.append(buffAux);
        communicator.send(buff, this->skt);
        buff.clear();
    }
    this->skt._shutdown();
    while (true) {
        std::string buffer = communicator.receive(this->skt);
        if (buffer == "") break;
        std::cout << buffer;
    }
}

Client::~Client() {
    this->skt._close();
}
