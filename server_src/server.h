#ifndef SERVER_SRC_SERVER_H_
#define SERVER_SRC_SERVER_H_

#include <iostream>
#include <string>
#include <utility>
#include <bits/stdc++.h>
#include "server_handler.h"
#include "../common_src/socket.h"
#include "server_handler.h"
#include "thread.h"

class Server {
 private:
    char *port;
    Socket skt;
    Socket clientSkt;
    Resources resources;
 public:
    // Creates the server and its sockets
    Server(char * rt, std::string root);
    // Connects the server to its port
    int connect();
    // Accepts the conection of its client
    void accept();
    void run();
    // The server receives a buffer from its client
    int receive(std::string &buffer, size_t size);
    int send(std::string &buffer, size_t size);
    // Closes the sockets of the server
    void close();
    void shutdown();
    // Destroys the sockets and puts the port back to NULL
    ~Server();
};

#endif  // SERVER_SRC_SERVER_H_
