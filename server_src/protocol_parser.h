#ifndef SERVER_SRC_PROTOCOL_PARSER_H_
#define SERVER_SRC_PROTOCOL_PARSER_H_

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "protocol.h"

class ProtocolParser {
 private:
 public:
    // Constructor y destructor
    ProtocolParser();
    ~ProtocolParser();

    // Obtiene el protocolo parseado del stream pasado por parametro
    Protocol *getProtocol(std::stringstream &stream, std::string &method,
                        std::string &resource, std::string &body);
};

#endif  // SERVER_SRC_PROTOCOL_PARSER_H_
