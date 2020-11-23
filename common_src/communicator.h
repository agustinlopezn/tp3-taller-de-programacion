#ifndef COMMON_SRC_COMMUNICATOR_H_
#define COMMON_SRC_COMMUNICATOR_H_

#include <string>
#include <string.h>
#include "socket.h"

class Communicator {
 private:
 public:
    // Constructor y destructor
    Communicator();

    ~Communicator();

    // Envia el string buffer mediante el socket pasado por parametro,
    // devolviendo la cantidad de bytes que efectivamente envio
    int send(std::string &buffer, Socket &skt);

    // Devuelve un string conteniendo la tira de bytes recibida
    // mediante el socket pasado por parametro
    std::string receive(Socket &skt);
};

#endif  // COMMON_SRC_COMMUNICATOR_H_
