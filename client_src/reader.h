#ifndef CLIENT_SRC_READER_H_
#define CLIENT_SRC_READER_H_

#include <sstream>
#include <iostream>
#include <string.h>

class Reader {
 public:
    // Constructor y destructor
    Reader();

    ~Reader();

    // Devuelve true si se llego a eof, false en caso contrario
    bool finished();

    // Devuelve la cantidad de bytes leidos de entrada estandar
    int read(char *buff, size_t size);
};

#endif  // CLIENT_SRC_READER_H_
