#include "client_handler.h"

ClientHandler::ClientHandler(Socket &client, Resources *resources) :
    client(std::move(client)), resources(resources), running(true) {}

void ClientHandler::run() {
    ProtocolParser parser;
    std::stringstream streamReceived;
    while (true) {
        std::string form = communicator.receive(&this->client);
        if (form == "") break;
        streamReceived << form;
        form.clear();
    }
    std::string method;
    std::string resource;
    std::string body;
    Protocol *protocol =  parser.getProtocol(streamReceived,
                            method, resource, body);
    std::string buffer = resources->getResponse(method, resource, body);
    if (buffer.size() == 0) this->stop();
    communicator.send(buffer, &this->client);
    buffer.clear();
    delete(protocol);
    this->stop();
}

bool ClientHandler::isAlive() {
    return !client.isClosed();
}

void ClientHandler::stop() {
    this->client._close();
}

ClientHandler::~ClientHandler() {
    this->client._close();
}
