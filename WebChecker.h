#ifndef WEBCHECKER_H
#define WEBCHECKER_H

#include <string>
// Checks website status
class WebChecker {
public:
    explicit WebChecker(const std::string &url);
    bool isOnline() const; // Returns true if  website HTTP Status within [200, 400)
    std::string getUrl() const; // Return the associated URL

private:
    std::string url_;
};

#endif // WEBCHECKER_H