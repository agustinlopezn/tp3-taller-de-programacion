#ifndef SERVER_SRC_RESPONSE_GET_SUCCESS_H_
#define SERVER_SRC_RESPONSE_GET_SUCCESS_H_

#include <string>
#include "response.h"

#define SUCCESS_GET "HTTP/1.1 200 OK\n\n"

class GetSuccess : public Response {
 private:
    std::string resource;
 public:
    // Constructor y destructor
    explicit GetSuccess(const std::string &resource) :
        resource(resource) {}

    ~GetSuccess() {}

    virtual std::string operator()() override {
        return SUCCESS_GET+resource;
    }
};

#endif  // SERVER_SRC_RESPONSE_GET_SUCCESS_H_
