#ifndef CLIENT_SRC_CLIENT_H_
#define CLIENT_SRC_CLIENT_H_

#include <string>
#include <string.h>
#include <utility>
#include "reader.h"
#include "../common_src/socket.h"
#include "../common_src/communicator.h"

class Client {
 private:
    const char *address;
    const char *port;
    Communicator communicator;
    Socket skt;
 public:
    Client(const char *address, const char *port);
    void start();
    int receive(std::string &buffer, size_t size);
    void close();
    void shutdown();
    ~Client();
};

#endif  // CLIENT_SRC_CLIENT_H_
