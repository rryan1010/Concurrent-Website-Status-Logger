#include "WebChecker.h"
#include <curl/curl.h>

WebChecker::WebChecker(const std::string &url) : url_(url) {}

// Returns the URL for validation
std::string WebChecker::getUrl() const {
    return url_;
}

bool WebChecker::isOnline() const { // Use libcurl to perform an HTTP HEAD request to determine status
    CURL *curl;
    CURLcode res;
    long httpCode(0);
    bool online = false;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url_.c_str());
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);  // HEAD request
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
            if (httpCode >= 200 && httpCode < 400)
                online = true;
        }
        curl_easy_cleanup(curl);
    }
    return online;
}