#include "server.h"

#define ACCEPT_QUEUE_LEN 10
#define SERVER_FLAG AI_PASSIVE
#define ERROR_CODE -1

Server::Server(char *port, Socket &socket, Socket &client) :
    port(port), skt(socket), clientSkt(client) {}

int Server::connect() {
    this->skt.start(this->port, true);

    return 0;
}

int Server::accept() {
    return this->skt._accept(this->clientSkt);
}

int Server::receive(unsigned char *buffer, size_t size) {
    return this->clientSkt.receive(buffer, size);
}

void Server::close() {
    this->skt._close();
    this->clientSkt._close();
}

Server::~Server() {
}
