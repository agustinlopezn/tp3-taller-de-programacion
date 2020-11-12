#ifndef COMMON_SRC_SOCKET_H_
#define COMMON_SRC_SOCKET_H_

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <utility>
#include <atomic>
#include <netdb.h>



class Socket {
 private:
    int fd;
    bool listens;
    int _connect(struct addrinfo *info);
    int bindListen(struct addrinfo *info);

 public:
    Socket();
    explicit Socket(bool listens);
    explicit Socket(int fd);
    Socket(Socket&& other);
    Socket& operator=(Socket&& other);
    // Starts the socket, binds it and puts it in listen mode if the boolean
    // is_server is true, otherwise connects it to the address.
    int start(const char *address, const char *port);

    // Accepts the conection and asigns it to the client fd
    Socket _accept();

    // Sends a message to the socket
    int _send(const char *message, size_t msg_len);

    // The socket receives a message comming from the connected socket
    int receive(char *buffer, size_t buffer_size);

    void _shutdown();
    // Closes the socket from both endpoints(RD and WR) if the socket
    // its a listener only the read channel otherwise.
    void _close();

    ~Socket();
};

#endif  // COMMON_SRC_SOCKET_H_
