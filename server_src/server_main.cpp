#include <string.h>
#include "server.h"
#include "resources.h"
#include "protocol_parser.h"
#include "../common_src/socket.h"

#define BLOCK_SIZE 64
#define PORT_POS 1
#define ROOT_POS 2
#define PARAMS_QNTY 3

int main(int argc, char *argv[]) {
    if (argc != PARAMS_QNTY) {
        std::cout << "Not enough parameters" << std::endl;
        return 1;
    }
    size_t size;
    // Socket socket(true);
    Server server(argv[PORT_POS]);
    if (server.connect()) {
        std::cout << "ERROR CONNECT" << std::endl;
        return 0;
    }
    std::string buffer;
    std::stringstream streamReceived;
    std::string input;
    /*while (input.compare("q") != 0) {
        getline(std::cin, input);
        server.receive(buffer, BLOCK_SIZE);
        streamReceived << buffer;
        buffer.clear();
    }*/ 
    server.accept();
    while (size = server.receive(buffer, BLOCK_SIZE), size > 0) {
        streamReceived << buffer;
        buffer.clear();
    }

    ProtocolParser parser;
    std::string method = "";
    std::string resource = "";
    std::string body = "";

    std::stringstream root(argv[ROOT_POS]);
    Resources resources(root.str());
    Protocol *protocol =  parser.getProtocol(streamReceived, method, resource, body);
    buffer += resources.manageResource(protocol->getMethod(), protocol->getResource(), protocol->getBody());

    server.send(buffer, BLOCK_SIZE);

    delete(protocol);
    server.close();
    return 0;
}
