#ifndef CLIENT_SRC_READER_H_
#define CLIENT_SRC_READER_H_

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <string.h>

class Reader {
 private:
    // std::istream file;
 public:
    Reader();
    bool finished();
    int read(char *buff, size_t size);
    ~Reader();
};

#endif  // CLIENT_SRC_READER_H_
