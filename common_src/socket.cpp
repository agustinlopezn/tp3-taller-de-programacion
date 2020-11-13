#define _POSIX_C_SOURCE 201112L  // Habilita getaddrinfo

#include "socket.h"
#include <string.h>
#include <errno.h>


#define ERROR_CODE -1
#define MAX_QUEUE_CLIENTS 20

Socket::Socket() {
    this->fd = -1;
    this->listens = false;
}

Socket::Socket(bool listens) {
    this->fd = -1;
    this->listens = listens;
}

Socket::Socket(int fd) {
    this->fd = fd;
    this->listens = false;
}

Socket::Socket(Socket&& other) {
    this->fd = std::move(other.fd);
    this->listens = std::move(other.listens);
    other.fd = -1;
}

Socket& Socket::operator=(Socket&& other) {
    if (this != &other) {
        this->fd = std::move(other.fd);
        this->listens = std::move(other.listens);
        other.fd = -1;
        other.listens = false;
    }
    return *this;
}


int Socket::_connect(struct addrinfo *info) {
    struct addrinfo *addr;
    int connection_status;

    for (addr = info; addr != NULL; addr = addr->ai_next) {
        int new_fd = socket(addr->ai_family,
                        addr->ai_socktype, addr->ai_protocol);
        if (new_fd != -1) {
            connection_status = connect(new_fd,
                                addr->ai_addr, addr->ai_addrlen);
            if (connection_status == 0) {
                this->fd = new_fd;
                return 0;
            }
        }
        std::cout << "Connection failure"  << std::endl;
    }

    return ERROR_CODE;
}

int Socket::bindListen(struct addrinfo *info) {
    struct addrinfo *addr;
    int bind_status;
    int val = 1;

    for (addr = info; addr != NULL; addr = addr->ai_next) {
        int new_fd = socket(addr->ai_family,
                        addr->ai_socktype, addr->ai_protocol);
        if (new_fd != -1) {
            if (setsockopt(new_fd, SOL_SOCKET, SO_REUSEADDR,
                        &val, sizeof(val)) == -1) {
                close(new_fd);
                throw "Fallo setsockopt";
            }
            bind_status = bind(new_fd, addr->ai_addr, addr->ai_addrlen);
            if (bind_status == 0 && listen(new_fd, MAX_QUEUE_CLIENTS) == 0) {
                this->fd = new_fd;
                return 0;
            } else if (bind_status == -1) {
                std::cout << "Bind error"  << std::endl;
            } else {
                std::cout << "Listen error"  << std::endl;
            }
            _close();
        }
    }
    return ERROR_CODE;
}

int Socket::start(const char *address, const char *port) {
    int status = 0;
    struct addrinfo hints;
    struct addrinfo *info;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = listens ? AI_PASSIVE : 0;

    if (listens) {
        getaddrinfo(NULL, port, &hints, &info);
        status = bindListen(info);
    } else {
        getaddrinfo(address, port, &hints, &info);
        status = _connect(info);
    }

    freeaddrinfo(info);

    return status;
}

int Socket::_send(const char *message, size_t msg_len) {
    size_t bytes_sent = 0;
    while (bytes_sent < msg_len) {
        int actually_sent = send(this->fd, &message[bytes_sent],
                            msg_len - bytes_sent, MSG_NOSIGNAL);
        if (actually_sent == 0) {
            fprintf(stderr, "Error in send :%s\n", strerror(errno));
            return 0;
        } else if (actually_sent == -1) {
            fprintf(stderr, "Error in send :%s\n", strerror(errno));
            return ERROR_CODE;
        }
        bytes_sent += (size_t)actually_sent;
    }
    return bytes_sent;
}

Socket Socket::_accept() {
    int new_fd = 0;

    new_fd = accept(this->fd, nullptr, nullptr);
    if (new_fd == -1) {
        throw std::invalid_argument("Socket");
    }

    return Socket(new_fd);
}

int Socket::receive(char *buffer, size_t buffer_size) {
    size_t bytes_received = 0;

    while (bytes_received < buffer_size) {
        int actually_received = recv(this->fd, &buffer[bytes_received],
                                buffer_size - bytes_received, 0);
        if (actually_received == -1) {
            std::cout << "Error in receive"  << std::endl;
            return ERROR_CODE;
        } else if (actually_received == 0) {
            bytes_received += (size_t)actually_received;
            return bytes_received;
        }
        bytes_received += (size_t)actually_received;
    }

    return bytes_received;
}

bool Socket::isClosed() {
    return this->fd == -1;
}

void Socket::_shutdown() {
    shutdown(this->fd, SHUT_WR);
}

void Socket::_close() {
    shutdown(this->fd, SHUT_RDWR);
    close(this->fd);
}

Socket::~Socket() {
    if (this->fd != -1) {
        this->fd = -1;
        this->listens = false;
    }
}
