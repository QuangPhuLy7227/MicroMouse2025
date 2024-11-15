#pragma once
#include <string>
#include <vector>

namespace mms_backend {
    class SettingsMazeFiles {
        public:
            SettingsMazeFiles() = delete;
            static std::vector<std::string> getAllPaths();
            static void addPath(const std::string& path);
            static void removePath(const std::string& path);

        private:
            static const std::string GROUP;
            static const std::string KEY_PATH;
    };
}