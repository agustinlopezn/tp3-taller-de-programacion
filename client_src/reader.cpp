#include "reader.h"

Reader::Reader() {
}

int Reader::read(char *buff, size_t size) {
    memset(buff, 0, size);
    std::cin.read(buff, size-1);
    return std::cin.gcount();
}

bool Reader::finished() {
    return std::cin.eof();
}

Reader::~Reader() {
}
