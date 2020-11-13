#include "protocol_parser.h"


ProtocolParser::ProtocolParser() {}

Protocol* ProtocolParser::getProtocol(std::stringstream &stream,
                std::string &method, std::string &resource, std::string &body) {
    size_t line = 1, bodyLine = 0;
    std::string buffer;
    while (std::getline(stream, buffer, '\n')) {
        if (line == 1) {
            std::cout << buffer << std::endl;
            std::string delimiter = " ";
            size_t pos = 0;
            size_t i = 0;
            while ((pos = buffer.find(delimiter)) != std::string::npos) {
                if (i == 0) {
                    method += buffer.substr(0, pos);
                    buffer.erase(0, pos + 1);
                } else if (i == 1) {
                    resource += buffer.substr(0, pos);
                    buffer.erase(0, pos + 1);
                }
                ++i;
            }
        } else if (buffer.empty()) {
            bodyLine = line + 1;
        }
        if (line >= bodyLine && bodyLine != 0) {
            body += buffer;
        }
        buffer.clear();
        ++line;
    }
    return new Protocol(method, resource, body);
}

ProtocolParser::~ProtocolParser() {
}
