#ifndef CLIENT_SRC_CLIENT_H_
#define CLIENT_SRC_CLIENT_H_

#include <string>
#include <utility>
#include <string.h>
#include "reader.h"
#include "../common_src/socket.h"
#include "../common_src/communicator.h"

class Client {
 private:
    const char *address;
    const char *port;
    Communicator communicator;
    Socket skt;
 public:
    // Constructor y destructor
    Client(const char *address, const char *port);

    ~Client();

    // Metodo princpipal del cliente, encargado de leer y enviar el petitorio
    // para luego recibir la respuesta del servidor e imprimirla por salida
    // estandar
    void start();
};

#endif  // CLIENT_SRC_CLIENT_H_
