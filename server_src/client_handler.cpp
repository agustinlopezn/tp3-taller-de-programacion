#include "client_handler.h"

ClientHandler::ClientHandler(Socket &skt) :
    serverSkt(skt) {}

void ClientHandler::run() {
    while (accepting) {
        //serverSkt._accept();
    }
}

ClientHandler::~ClientHandler() {

}