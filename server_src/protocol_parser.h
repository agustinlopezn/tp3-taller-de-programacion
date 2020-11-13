#ifndef SERVER_SRC_PROTOCOL_PARSER_H_
#define SERVER_SRC_PROTOCOL_PARSER_H_

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class ProtocolParser {
 private:
 public:
    ProtocolParser();
    void getProtocol(std::stringstream &stream, std::string &method,
                        std::string &resource, std::string &body);
    ~ProtocolParser();
};

#endif  // SERVER_SRC_PROTOCOL_PARSER_H_
