#ifndef SERVER_SRC_RESPONSE_H_
#define SERVER_SRC_RESPONSE_H_

#include <string>

class Response {
 private:
 public:
    // Metodo a sobreescribir por las clases herederas
    // realizando implementacion propia de la respuesta
    // a un petitorio HTTP
    virtual std::string operator()() = 0;

    // Destructor
    virtual ~Response() = default;
};

#endif  // SERVER_SRC_RESPONSE_H_
