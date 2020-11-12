
#include <string>
#include <string.h>
#include "socket.h"

class Communicator {
 private:
 public:
    Communicator();
    int send(std::string &buffer, Socket *skt);
    std::string receive(Socket *skt);
    ~Communicator();
};