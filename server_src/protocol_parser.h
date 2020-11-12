#ifndef SERVER_SRC_PROTOCOL_PARSER_H_
#define SERVER_SRC_PROTOCOL_PARSER_H_

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "protocol.h"

class ProtocolParser {
 private:
    // std::ifstream file;
 public:
    ProtocolParser();
    Protocol* getProtocol(std::stringstream &stream, std::string &method, std::string &resource, std::string &body);
    ~ProtocolParser();
};

#endif  // SERVER_SRC_PROTOCOL_PARSER_H_
