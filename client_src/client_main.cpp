#include "client.h"

#define ADDR_POS 1
#define PORT_POS 2
#define BUFF_SIZE 64

int main(int argc, char *argv[]) {
    Client client(argv[ADDR_POS], argv[PORT_POS]);
    client.start();
    client.close();
    return 0;
}
