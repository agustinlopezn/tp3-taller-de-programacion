#ifndef SERVER_SRC_SERVER_H_
#define SERVER_SRC_SERVER_H_

#include <utility>
#include <string>
#include "server_handler.h"
#include "thread.h"

class Server {
 private:
    char *port;
    Socket skt;
    Resources resources;
 public:
    Server(char *port, const std::string &root);
    void accept();
    void run();
    ~Server();
};

#endif  // SERVER_SRC_SERVER_H_
