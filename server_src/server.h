#ifndef SERVER_SRC_SERVER_H_
#define SERVER_SRC_SERVER_H_

#include <utility>
#include <string>
#include "server_handler.h"
#include "thread.h"

class Server {
 private:
    char *port;
    Socket skt;
    Resources resources;
 public:
    // Constructor y destructor
    Server(char *port, const std::string &root);
    ~Server();

    // Metodo principal que lanza un thread server handler
    // sediendole el ownership del socket. Se detiene cuando
    // se oprime el caracter 'q'
    void run();
};

#endif  // SERVER_SRC_SERVER_H_
