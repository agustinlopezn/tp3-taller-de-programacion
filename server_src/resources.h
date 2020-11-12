#include <map>
#include <string>

class Resources{
 private:
    std::map <std::string, std::string> resources;
 public:
    explicit Resources(std::string root);
    std::string getResource(std::string resourceName);
    std::string postResource(std::string resourceName, std::string resource);
    std::string manageResource(std::string method, std::string resourceName, std::string resource);
    ~Resources();
};


