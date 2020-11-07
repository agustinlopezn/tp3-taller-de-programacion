#ifndef __SOCKET_H
#define __SOCKET_H

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

class Socket {
 private:
    int fd;
    int _connect(struct addrinfo *info);
    int bindListen(struct addrinfo *info);
 public:
    Socket();
    // Starts the socket, binds it and puts it in listen mode if the boolean
    // is_server is true, otherwise connects it to the address.
    int start(const char *port, bool listens);

    // Accepts the conection and asigns it to the client fd
    int _accept(Socket &client);

    // Sends a message to the socket
    int _send(unsigned char *message, size_t msg_len);

    // The socket receives a message comming from the connected socket
    int receive(unsigned char *buffer, size_t buffer_size);

    // Closes the socket from both endpoints(RD and WR)
    int _close();

    ~Socket();
};

#endif  // LOCK_H_
