#ifndef SERVER_SRC_RESPONSE_GET_ERROR_H_
#define SERVER_SRC_RESPONSE_GET_ERROR_H_

#include <string>
#include "response.h"

#define GET_ERROR "HTTP/1.1 404 NOT FOUND\n\n"

class GetError : public Response {
 private:
 public:
    // Constructor y destructor
    GetError() {}

    ~GetError() {}

    virtual std::string respond() override {
        return GET_ERROR;
    }
};

#endif  // SERVER_SRC_RESPONSE_GET_ERROR_H_
