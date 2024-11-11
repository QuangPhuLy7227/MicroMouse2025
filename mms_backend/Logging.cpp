#include "Logging.h"
#include "AssertMacros.h"
#include <iostream>
#include <sstream>
#include <mutex>

namespace mms_backend {
    static std::mutex logMutex;
    void Logging::init() {
        std::cout << "Logging initialized." << std::endl;
    }

    void Logging::handler(const std::string& type, const std::string& file, int line, const std::string& msg) {
        std::lock_guard<std::mutex> lock(logMutex);
        std::ostringstream formatted;
        formatted << "[" << file << ":" << line << "] - " << msg;

        std::cout << formatted.str() << std::endl;
    }
}