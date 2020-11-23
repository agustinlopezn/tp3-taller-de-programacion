#include "resources.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "lock.h"
#include "response_get_error.h"
#include "response_method_error.h"
#include "response_post_error.h"
#include "response_post_success.h"
#include "response_get_success.h"

#define ROOT_MSG "\nContent-Type: text/html\n\n"


Resources::Resources(std::string root) {
    std::ifstream rootFile(root);
    std::stringstream stream;
    stream << rootFile.rdbuf();
    resources.insert({"/", ROOT_MSG+stream.str()});
}

Response *Resources::getResource(std::string resourceName) {
    if (resources.find(resourceName) == resources.end())
        return new GetError();
    return new GetSuccess(resources.at(resourceName));
}

Response *Resources::postResource(std::string resourceName,
                                const std::string &resource) {
    if (resourceName == "/")
        return new PostError();
    resources[resourceName] = resource;
    return new PostSuccess(resource);
}

Response *Resources::getResponse(Protocol *protocol) {
    Lock lock(m);
    std::string method = protocol->getMethod();
    std::string resourceName = protocol->getResource();
    if (method == "GET")
        return getResource(resourceName);
    if (method == "POST")
        return postResource(resourceName, protocol->getBody());
    return new MethodError(method);
}

Resources::~Resources() {
}
