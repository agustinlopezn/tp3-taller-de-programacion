#include "protocol.h"

Protocol::Protocol(std::string &method, std::string &resource, std::string &body) :
    method(method), resource(resource), body(body) {}

std::string Protocol::getMethod() {
    // std::cout << "Get method Protocol" << method << std::endl;
    return this->method;
}

std::string Protocol::getResource() {
    // std::cout << "Get resource Protocol: " << resource << std::endl;
    return this->resource;
}

std::string Protocol::getBody() {
    // std::cout << "Get body Protocol: " << body << std::endl;
    return this->body;
}

Protocol::~Protocol() {

}
