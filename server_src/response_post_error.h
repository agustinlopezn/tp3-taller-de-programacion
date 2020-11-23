#ifndef SERVER_SRC_RESPONSE_POST_ERROR_H_
#define SERVER_SRC_RESPONSE_POST_ERROR_H_

#include <string>
#include "response.h" 

#define POST_ERROR "HTTP/1.1 403 FORBIDDEN\n\n"

class PostError : public Response {
 private:
 public:
    // Constructor y destructor
    PostError() {}
    ~PostError() {}

    virtual std::string respond() override {
        return POST_ERROR;
    }
};

#endif  // SERVER_SRC_RESPONSE_POST_ERROR_H_
