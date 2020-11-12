#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "../common_src/socket.h"
#include "client_handler.h"
// #include "thread.h"
//public Thread
class Server  {
 private:
    const char *port;
    Socket skt;
    Socket clientSkt;
 public:
    // Creates the server and its sockets
    Server(const char *port);
    // void run() override;
    // Connects the server to its port
    int connect();
    // Accepts the conection of its client

    void accept();
    // The server receives a buffer from its client
    int receive(std::string &buffer, size_t size);
    int send(std::string &buffer, size_t size);
    // Closes the sockets of the server
    void close();
    void shutdown();
    // Destroys the sockets and puts the port back to NULL
    ~Server();
};

#endif // SERVER_H
