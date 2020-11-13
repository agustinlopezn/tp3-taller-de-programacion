#include "server.h"

#define ACCEPT_QUEUE_LEN 10
#define SERVER_FLAG AI_PASSIVE
#define ERROR_CODE -1

Server::Server(char *port, std::string root) :
    port(port), skt(true), resources(root) {}

void Server::run() {
    this->skt.start(NULL, port);
    Thread *handler = new ServerHandler(skt, &resources);
    handler->run();
    std::string input;
    while (input != "q") {
        std::cin >> input;
        std::cout << "input" << std::endl;
        input.clear();
    }
    handler->stop();
    handler->join();
    delete(handler);
}

int Server::connect() {
    this->skt.start(NULL, this->port);
    return 0;
}

void Server::accept() {
    this->clientSkt = std::move(this->skt._accept());
}

int Server::receive(std::string &buffer, size_t size) {
    char buf[64];
    memset(buf, 0, 64);
    int bytesReceived = this->clientSkt.receive(buf, size);
    for (int i = 0; i < bytesReceived; ++i) {
        buffer+=buf[i];
    }
    return bytesReceived;
}

void Server::shutdown() {
    this->skt._shutdown();
}

int Server::send(std::string &buffer, size_t size) {
    return this->clientSkt._send(buffer.c_str(), size);
}

void Server::close() {
    this->skt._close();
    this->clientSkt._close();
}

Server::~Server() {
}
