#ifndef CLIENT_SRC_READER_H_
#define CLIENT_SRC_READER_H_

#include <sstream>
#include <iostream>
#include <string.h>

class Reader {
 public:
    Reader();
    bool finished();
    int read(char *buff, size_t size);
    ~Reader();
};

#endif  // CLIENT_SRC_READER_H_
