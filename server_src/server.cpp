#include "server.h"

Server::Server(char *port, const std::string &root) :
    port(port), skt(NULL, port, true), resources(root) {}

void Server::run() {
    Thread *handler = new ServerHandler(std::move(skt), &resources);
    handler->start();
    while (getc(stdin) != 'q') {
    }
    handler->stop();
    handler->join();
    delete(handler);
}

Server::~Server() {
    if (!this->skt.isClosed()) {
        this->skt._close();
    }
}
