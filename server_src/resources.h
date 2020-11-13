#ifndef SERVER_SRC_RESOURCES_H_
#define SERVER_SRC_RESOURCES_H_

#include <map>
#include <string>
#include <mutex>

class Resources{
 private:
    std::map <std::string, std::string> resources;
    std::mutex m;
    std::string getResource(std::string resourceName);
    std::string postResource(std::string resourceName, std::string resource);
 public:
    explicit Resources(std::string root);
    std::string getResponse(std::string method,
               std::string resourceName, std::string resource);
    ~Resources();
};

#endif  // SERVER_SRC_RESOURCES_H_
