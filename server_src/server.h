#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <string>
#include "../common_src/socket.h"

class Server {
 private:
    char *port;
    Socket &skt;
    Socket &clientSkt;
 public:
    // Creates the server and its sockets
    Server(char *port, Socket &socket, Socket &client);
    // Connects the server to its port
    int connect();
    // Accepts the conection of its client
    int accept();
    // The server receives a buffer from its client
    int receive(unsigned char *buffer, size_t size);
    // Closes the sockets of the server
    void close();
    // Destroys the sockets and puts the port back to NULL
    ~Server();
};

#endif // SERVER_H
