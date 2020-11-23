#ifndef SERVER_SRC_SERVER_HANDLER_H_
#define SERVER_SRC_SERVER_HANDLER_H_

#include <string>
#include <iostream>
#include <atomic>
#include <vector>
#include <utility>
#include "thread.h"
#include "client_handler.h"
#include "../common_src/socket.h"

class ServerHandler : public Thread {
 private:
    Socket serverSkt;
    Resources *resources;
    Communicator communicator;
    std::atomic_bool accepting;
    std::vector<Thread*> clients;
    void killClients(bool killAll);

 public:
    // Constructor y destructor
    ServerHandler(Socket skt, Resources *resources);
    ~ServerHandler();

    // Realiza override de run de Thread:
    // Recibe el petitorio, lo parsea y envia la respuesta al cliente
    void run() override;

    // Realiza override de stop de Thread:
    // Pasa a modo no aceptador y cierra su socket
    void stop() override;

    // Realiza override de isAlive de Thread:
    // Devuelve true si el socket del servidor esta en un estado valido
    bool isAlive() override;

    // Realiza una limpieza de los threads clientes que estan desconectados
    void killInactiveClients();

    // Realiza una limpieza de todos los threads clientes
    void killAllClients();
};

#endif  // SERVER_SRC_SERVER_HANDLER_H_
