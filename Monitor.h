#ifndef MONITOR_H
#define MONITOR_H

#include "WebChecker.h"
#include <vector>
#include <string>
#include <mutex>
#include <map>

class Monitor {
public:
    Monitor(); // Check Monitor.cpp file
    void addWebsite(const std::string &url); 
    void removeWebsite(const std::string &url); 
    void checkAll(); // Concurrently check all websites.
    std::map<std::string, bool> getStatus() const; // Return current website statuses.

private:
    mutable std::mutex mtx_;    // Mutex to ensure thread-safe access.
    std::vector<WebChecker> websites_;
    std::map<std::string, bool> status_;
};

#endif // MONITOR_H