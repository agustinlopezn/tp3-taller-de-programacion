#ifndef SERVER_SRC_RESOURCES_H_
#define SERVER_SRC_RESOURCES_H_

#include <map>
#include <string>
#include <mutex>
#include "response.h"
#include "protocol.h"

class Resources{
 private:
    std::map <std::string, std::string> resources;
    std::mutex m;
    Response *getResource(std::string resourceName);
    Response *postResource(std::string resourceName,
                           const std::string &resource);
 public:
    // Constructor y destructor
    explicit Resources(std::string root);
    ~Resources();

    // Devuelve un objeto Response dinamico que genera polimorficamente
    // la respuesta del servidor al protocolo indicado
    Response *getResponse(Protocol *protocol);
};

#endif  // SERVER_SRC_RESOURCES_H_
