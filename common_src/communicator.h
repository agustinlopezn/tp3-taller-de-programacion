#ifndef COMMON_SRC_COMMUNICATOR_H_
#define COMMON_SRC_COMMUNICATOR_H_

#include <string>
#include <string.h>
#include "socket.h"

class Communicator {
 private:
 public:
    Communicator();
    int send(std::string &buffer, Socket &skt);
    std::string receive(Socket &skt);
    ~Communicator();
};

#endif  // COMMON_SRC_COMMUNICATOR_H_
