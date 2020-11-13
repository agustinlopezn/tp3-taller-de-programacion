#include "server.h"

Server::Server(char *port, std::string root) :
    port(port), skt(true), resources(root) {}

void Server::run() {
    this->skt.start(NULL, port);
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
