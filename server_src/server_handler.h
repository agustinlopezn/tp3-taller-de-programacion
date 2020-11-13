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
    ServerHandler(Socket skt, Resources *resources);
    void run() override;
    void stop() override;
    bool isAlive() override;
    void killInactiveClients();
    void killAllClients();
    ~ServerHandler();
};

#endif  // SERVER_SRC_SERVER_HANDLER_H_
