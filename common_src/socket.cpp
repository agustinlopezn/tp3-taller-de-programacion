#define _POSIX_C_SOURCE 201112L // Habilita getaddrinfo

#include "socket.h"
#include <string.h>

#define ERROR_CODE -1

Socket::Socket() {
    this->fd = -1;
}

int Socket::_connect(struct addrinfo *info) {
    struct addrinfo *addr;
    int connection_status;

    for (addr = info; addr != NULL; addr = addr->ai_next) {
        this->fd = socket(addr->ai_family,
                        addr->ai_socktype, addr->ai_protocol);
        if (this->fd != -1) {
            connection_status = connect(this->fd,
                                addr->ai_addr, addr->ai_addrlen);
            if (connection_status == 0) {
                return 0;
            }
            std::cout << "Connection failure"  << std::endl;
        }
    }

    return ERROR_CODE;
}

int Socket::bindListen(struct addrinfo *info) {
    struct addrinfo *addr;
    int bind_status;

    for (addr = info; addr != NULL; addr = addr->ai_next) {
        this->fd = socket(addr->ai_family,
                        addr->ai_socktype, addr->ai_protocol);
        if (this->fd != -1) {
            bind_status = bind(this->fd, addr->ai_addr, addr->ai_addrlen);
            if (bind_status == 0 && listen(this->fd, 1) == 0) {
                return 0;
            } else if (bind_status == -1) {
                std::cout << "Bind error"  << std::endl;;
            } else {
                std::cout << "Listen error"  << std::endl;
            }
            _close();
        }
    }
    return ERROR_CODE;
}

int Socket::start(const char *port, bool listens) {
    int status = 0;
    struct addrinfo hints, *info;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (listens) {
        getaddrinfo(NULL, port, &hints, &info);
        status = bindListen(info);
    } else {
        getaddrinfo(NULL, port, &hints, &info);
        status = _connect(info);
    }
    freeaddrinfo(info);
    return status;
}

int Socket::_send(unsigned char *message, size_t msg_len) {
    size_t bytes_sent = 0;

    while (bytes_sent < msg_len) {
        int actually_sent = send(this->fd, &message[bytes_sent],
                            msg_len - bytes_sent, MSG_NOSIGNAL);

        if (actually_sent == 0) {
            return 0;
        } else if (actually_sent == -1) {
            // fprintf(stderr, "Error in send :%s\n", strerror(errno));
            return ERROR_CODE;
        }
        bytes_sent += (size_t)actually_sent;
    }
    return bytes_sent;
}

int Socket::_accept(Socket &client) {
    struct sockaddr_in address;
    socklen_t address_length = (socklen_t) sizeof(address);

    client.fd = accept(this->fd, (struct sockaddr *)&address, &address_length);
    if (client.fd == -1) {
        std::cout << "Error in accept"  << std::endl;
        return ERROR_CODE;
    }
    return 0;
}

int Socket::receive(unsigned char *buffer, size_t buffer_size) {
    size_t bytes_received = 0;

    while (bytes_received < buffer_size) {
        int actually_received = recv(this->fd, &buffer[bytes_received],
                                buffer_size - bytes_received, 0);
        if (actually_received == -1) {
            std::cout << "Error in receive"  << std::endl;
            // fprintf(stderr, "Error in receive: %s\n", strerror(errno));
            return ERROR_CODE;
        } else if (actually_received == 0) {
            return 0;
        }
        bytes_received += (size_t)actually_received;
    }
    return bytes_received;
}

int Socket::_close() {
    shutdown(this->fd, SHUT_RDWR);
    close(this->fd);
    return 0;
}

Socket::~Socket() {
    this->fd = -1;
}
