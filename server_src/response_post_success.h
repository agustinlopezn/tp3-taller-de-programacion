#ifndef SERVER_SRC_RESPONSE_POST_SUCCESS_H_
#define SERVER_SRC_RESPONSE_POST_SUCCESS_H_

#include <string>
#include "response.h"

#define SUCCESS_POST "HTTP/1.1 200 OK\n\n"

class PostSuccess : public Response {
 private:
    std::string resource;

 public:
    // Constructur y destructor
    explicit PostSuccess(const std::string &resource) :
        resource(resource) {}

    ~PostSuccess() {}

    virtual std::string respond() override {
        return SUCCESS_POST + resource;
    }
};

#endif  // SERVER_SRC_RESPONSE_POST_SUCCESS_H_
