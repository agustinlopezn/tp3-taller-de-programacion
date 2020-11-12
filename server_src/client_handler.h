#ifndef CLIENT_HANDLER_H_
#define CLIENT_HANDLER_H_

#include <string>
#include <iostream>
#include <atomic>
#include <vector>
#include "thread.h"
#include "../common_src/socket.h"

class ClientHandler : public Thread {
 private:
    std::vector<Thread*> clients;
    std::atomic_bool accepting;
    Socket &serverSkt;
 public:
    ClientHandler(Socket &skt);
    void run() override;
    ~ClientHandler();
};

#endif // CLIENT_HANDLER_H_