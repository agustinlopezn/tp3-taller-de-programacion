#include "protocol_parser.h"


ProtocolParser::ProtocolParser() {}

Protocol *ProtocolParser::getProtocol(std::stringstream &stream,
                std::string &method, std::string &resource, std::string &body) {
    size_t line = 2, bodyLine = 0;
    std::string buffer, protocol;
    stream >> method;
    stream >> resource;
    stream >> protocol;
    std::cout << method << " " + resource << " " + protocol << std::endl;
    std::getline(stream, buffer, '\n');

    while (std::getline(stream, buffer, '\n')) {
        if (buffer.empty()) {
            bodyLine = line + 1;
        }
        if (line >= bodyLine && bodyLine != 0) {
            body.append(buffer);
            body.append("\n");
        }
        buffer.clear();
        ++line;
    }

    return new Protocol(method, resource, body);
}

ProtocolParser::~ProtocolParser() {
}
