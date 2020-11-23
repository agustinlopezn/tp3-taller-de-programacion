#ifndef COMMON_SRC_SOCKET_H_
#define COMMON_SRC_SOCKET_H_

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <utility>
#include <atomic>
#include <netdb.h>
#include <stdexcept>


class Socket {
 private:
    int fd;
    bool listens;
    int _connect(struct addrinfo *info);
    int bindListen(struct addrinfo *info);

 public:
    // Constructor y destructor
    Socket();
    ~Socket();

    // Constructor que inicializa con el parametro
    // pasado al atributo de la clase
    explicit Socket(bool listens);
    explicit Socket(int fd);

    // Constructor por movimiento
    Socket(Socket&& other);
    Socket& operator=(Socket&& other);

    // Startea el socket,lo bindea y lo pone en modo escuchante si el booleando
    // is_server es true, sino realiza un connect al address pasado por param.
    int start(const char *address, const char *port);

    // Acepta la coneccion entrante
    Socket _accept();
    // Envia message al socket
    int _send(const char *message, size_t msg_len);

    // El socket recibe un mensaje proveniente del socket conectado
    int receive(char *buffer, size_t buffer_size);

    // Devuelve verdadero si el socket esta en un estado invalido
    // false en otro caso
    bool isClosed();

    // Realiza un shutdown del canal de escritura
    void _shutdown();

    // Cierra el socket tanto para lectura como para escritura
    void _close();
};

#endif  // COMMON_SRC_SOCKET_H_
