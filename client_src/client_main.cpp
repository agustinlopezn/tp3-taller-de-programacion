#include <sstream>
#include <fstream>
#include "reader.h"
#include "client.h"
#include "../common_src/socket.h"

#define ADDR_POS 1
#define PORT_POS 2
#define BUFF_SIZE 64

int main(int argc, char *argv[]) {
    char buff[BUFF_SIZE];
    memset(buff, 0, BUFF_SIZE);
    Reader reader;
    Socket socket(false);
    Client client(argv[ADDR_POS], argv[PORT_POS], socket);
    client.connect();

    while (!reader.finished()) {
        size_t size = reader.read(buff, BUFF_SIZE);
        if (size < 1) break;
        client.send(buff, size);
    }
    std::string buffer;
    client.shutdown();
    client.receive(buffer, BUFF_SIZE);
    std::cout << buffer;
    client.close();
    return 0;
}