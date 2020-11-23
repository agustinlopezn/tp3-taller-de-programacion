#ifndef SERVER_SRC_RESPONSE_METHOD_ERROR_H_
#define SERVER_SRC_RESPONSE_METHOD_ERROR_H_

#include <string>
#include "response.h"

#define METHOD_ERROR "HTTP/1.1 405 METHOD NOT ALLOWED\n\n"
#define INVALID_ACTION " es un comando desconocido\n"

class MethodError : public Response {
 private:
    std::string method;
 public:
    // Constructor y destructor
    explicit MethodError(const std::string &method) :
        method(method) {}

    ~MethodError() {}

    virtual std::string operator()() override {
        return METHOD_ERROR+method+INVALID_ACTION;
    }
};

#endif  // SERVER_SRC_RESPONSE_METHOD_ERROR_H_
