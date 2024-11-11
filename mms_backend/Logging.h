#pragma once

#include <iostream>
#include <string>

namespace mms_backend {
    class Logging {
        public:
            Logging() = delete;
            static void init();

        private:
            static void handler(const std::string& type, const std::string& file, int line, const std::string& msg);
    };
}