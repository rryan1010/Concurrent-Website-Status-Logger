#include "Monitor.h"
#include <thread>
#include <algorithm>

Monitor::Monitor() {}


void Monitor::addWebsite(const std::string &url) {
    std::lock_guard<std::mutex> lock(mtx_);
    websites_.emplace_back(url);
}

// Removes a URL from the websites vector and status map
void Monitor::removeWebsite(const std::string &url) {
    std::lock_guard<std::mutex> lock(mtx_);
    websites_.erase(
        std::remove_if(websites_.begin(), websites_.end(),
                       [&url](const WebChecker &checker) {
                           return checker.getUrl() == url;
                       }),
        websites_.end());
    status_.erase(url);
}

// Checks each website concurrently and updates the status map
void Monitor::checkAll() {
    std::vector<std::thread> threads;
    {
        std::lock_guard<std::mutex> lock(mtx_);
        for (auto &checker : websites_) {
            threads.emplace_back([this, &checker]() {
                bool online = checker.isOnline();
                std::lock_guard<std::mutex> lock(mtx_);
                status_[checker.getUrl()] = online;
            });
        }
    }
    for (auto &t : threads) {
        if (t.joinable())
            t.join();
    }
}

// Returns a snapshot of the current status for each monitored website
std::map<std::string, bool> Monitor::getStatus() const {
    std::lock_guard<std::mutex> lock(mtx_);
    return status_;
}