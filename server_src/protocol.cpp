#include "protocol.h"

Protocol::Protocol(std::string &method, std::string &resource, std::string &body) :
    method(method), resource(resource), body(body) {}

std::string Protocol::getMethod() {
    return this->method;
}

std::string Protocol::getResource() {
    return this->resource;
}

std::string Protocol::getBody() {
    return this->body;
}

Protocol::~Protocol() {

}
