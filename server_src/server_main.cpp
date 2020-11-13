#include "server.h"

#define BLOCK_SIZE 64
#define PORT_POS 1
#define ROOT_POS 2
#define PARAMS_QNTY 3

int main(int argc, char *argv[]) {
    if (argc != PARAMS_QNTY) {
        std::cout << "Not enough parameters" << std::endl;
        return 1;
    }
    Server server(argv[PORT_POS], argv[ROOT_POS]);
    server.run();
    return 0;
}
