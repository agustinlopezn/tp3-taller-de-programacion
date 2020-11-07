#include "server.h"
#include "../common_src/socket.h"
#include <string.h>

#define BLOCK_SIZE 64
#define PORT_POS 1

int main(int argc, char *argv[]) {
    unsigned char buffer[BLOCK_SIZE];
    size_t size;
    Socket socket;
    Socket client;
    Server server(argv[PORT_POS], socket, client);
    if (server.connect()) {
        std::cout << "ERROR CONNECT" << std::endl;
        return 0;
    }
    if (server.accept()) {
        std::cout << "ERROR ACCEPT" << std::endl;
        return 0;
    }
    memset(buffer, 0, BLOCK_SIZE);
    while (size = server.receive(buffer, BLOCK_SIZE), size > 0) {
        std::cout << buffer << std::endl;
        memset(buffer, 0, BLOCK_SIZE);
    }
    fprintf(stdout, "%s", buffer);
    server.close();
    return 0;
}