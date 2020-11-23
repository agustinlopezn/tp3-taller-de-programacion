#ifndef SERVER_SRC_CLIENT_HANDLER_H_
#define SERVER_SRC_CLIENT_HANDLER_H_

#include <string>
#include <utility>
#include "thread.h"
#include "resources.h"
#include "protocol_parser.h"
#include "../common_src/socket.h"
#include "../common_src/communicator.h"

class ClientHandler : public Thread {
 private:
    Socket client;
    Communicator communicator;
    Resources *resources;
    bool running;
 public:
    // Constructor y destructor
    ClientHandler(Socket &client, Resources *resources);
    ~ClientHandler();

    // Realiza override de run de Thread:
    // Recibe el petitorio, lo parsea y envia la respuesta al cliente
    void run() override;

    // Realiza override de stop de Thread:
    // Cierra el socket del cliente
    void stop() override;

    // Realiza override de isAlive de Thread:
    // Devuelve true si el socket del cliente esta en un estado valido
    bool isAlive() override;
};

#endif  // SERVER_SRC_CLIENT_HANDLER_H_
