#ifndef CLIENT_SRC_CLIENT_H_
#define CLIENT_SRC_CLIENT_H_

#include <string>
#include <string.h>
#include "../common_src/socket.h"

class Client {
 private:
    const char *address;
    const char *port;
    Socket &skt;
 public:
    Client(const char *address, const char *port, Socket &skt);
    void connect();
    int send(char *buffer, size_t size);
    int receive(std::string &buffer, size_t size);
    void close();
    void shutdown();
    ~Client();
};

#endif  // CLIENT_SRC_CLIENT_H_
