#include "server_handler.h"

ServerHandler::ServerHandler(Socket &skt, Resources *resources) :
    serverSkt(std::move(skt)), resources(resources), accepting(true) {}

void ServerHandler::run() {
    std::string buffer = "";
    while (accepting) {
        Socket client = serverSkt._accept();
        if (client.isClosed()) break;
        Thread *clientHandler = new ClientHandler(client, resources);
        clientHandler->run();
        clients.push_back(clientHandler);
        killInactiveClients();
    }
    std::cout << "SALI" << std::endl;
    killAllClients();
}

void ServerHandler::killAllClients() {
    killClients(true);
}

void ServerHandler::killInactiveClients() {
    killClients(false);
}

void ServerHandler::killClients(bool killAll) {
    std::vector<Thread *>::iterator it = clients.begin();
    while (it != clients.end()) {
        if (!(*it)->isAlive() || killAll) {
            if ((*it)->isAlive()) (*it)->stop();
            delete *it;
            it = clients.erase(it);
        } else {
            it++;
        }
    }
}

bool ServerHandler::isAlive() {
    return !this->serverSkt.isClosed();
}

void ServerHandler::stop() {
    this->accepting = false;
    this->serverSkt._close();
}

ServerHandler::~ServerHandler() {
}
