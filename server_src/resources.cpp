#include "resources.h"
#include <iostream>
#include <fstream>
#include <sstream>

#define GET_ERROR "​ HTTP/1.1 404 NOT FOUND\n\n"
#define SUCCESS_MSG " HTTP/1.1 200 OK\n\n​"
#define POST_ERROR " HTTP/1.1 403 FORBIDDEN\n\n"
#define METHOD_ERROR " ​HTTP/1.1 405 METHOD NOT ALLOWED\n\n"


Resources::Resources(std::string root) {
    std::ifstream rootFile(root);
    std::stringstream stream;
    stream << rootFile.rdbuf();
    resources.insert({"/", stream.str()});
}

std::string Resources::getResource(std::string resourceName) {
    if (resources.find(resourceName) == resources.end()) {
        return new GetError(); //GET_ERROR;
    }
    return SUCCESS_MSG+resources.at(resourceName);
}
std::string Resources::postResource(std::string resourceName, std::string resource) {
    if (resourceName == "/") {
        return new PostError(); // POST_ERROR;
    }
    resources.insert({resourceName, resource});
    return SUCCESS_MSG+resource;
}
std::string Resources::getResponse(std::string method, std::string resourceName, std::string resource) {
    if (method == "GET") return getResource(resourceName);
    if (method == "POST") return postResource(resourceName, resource);
    return new MethodError(); // METHOD_ERROR;
}
Resources::~Resources() {
}
