#include "resources.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "lock.h"

#define GET_ERROR "HTTP/1.1 404 NOT FOUND\n\n"
#define SUCCESS_MSG "HTTP/1.1 200 OK\n\n"
#define POST_ERROR "HTTP/1.1 403 FORBIDDEN\n\n"
#define METHOD_ERROR "HTTP/1.1 405 METHOD NOT ALLOWED\n\n"
#define INVALID_ACTION " es un comando desconocido\n"
#define ROOT_MSG "\nContent-Type: text/html\n\n"


Resources::Resources(std::string root) {
    std::ifstream rootFile(root);
    std::stringstream stream;
    stream << rootFile.rdbuf();
    resources.insert({"/", ROOT_MSG+stream.str()});
}

std::string Resources::getResource(std::string resourceName) {
    if (resources.find(resourceName) == resources.end()) {
        return GET_ERROR;  // new GetError();
    }
    return SUCCESS_MSG+resources.at(resourceName);
}
std::string Resources::postResource(std::string resourceName,
                                const std::string &resource) {
    if (resourceName == "/") {
        return POST_ERROR;  // new PostError();
    }
    resources[resourceName] = resource;
    return SUCCESS_MSG+resource;
}
std::string Resources::getResponse(const std::string &method,
                const std::string &resourceName, const std::string &resource) {
    Lock lock(m);
    if (method == "GET") return getResource(resourceName);
    if (method == "POST") return postResource(resourceName, resource);
    return METHOD_ERROR+method+INVALID_ACTION;  // new MethodError();
}
Resources::~Resources() {
}
