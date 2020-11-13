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
    bool running;
    Communicator communicator;
    Resources *resources;
 public:
    ClientHandler(Socket &client, Resources *resources);
    void run() override;
    void stop() override;
    bool isAlive() override;
    ~ClientHandler();
};

#endif  // SERVER_SRC_CLIENT_HANDLER_H_
