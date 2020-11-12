#ifndef SERVER_SRC_PROTOCOL_H_
#define SERVER_SRC_PROTOCOL_H_

#include <string>
#include <iostream>

class Protocol {
 private:
    std::string &method;
    std::string &resource;
    std::string &body;
 public:
    Protocol(std::string &method, std::string &resource, std::string &body);
    std::string getMethod();
    std::string getResource();
    std::string getBody();
    ~Protocol();
};

#endif  // SERVER_SRC_PROTOCOL_H_
