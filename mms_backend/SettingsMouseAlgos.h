#pragma once
#include <string>
#include <vector>

namespace mms_backend {
    class SettingsMouseAlgos {
        public:
            SettingsMouseAlgos() = delete;
            static std::vector<std::string> names();
            static std::string getDirectory(const std::string& name);
            static std::string getBuildCommand(const std::string& name);
            static std::string getRunCommand(const std::string& name);

            static void add(const std::string& name, const std::string& directory, const std::string& buildCommand, const std::string& runCommand);
            static void update(const std::string& name, const std::string& newName, const std::string& newDirectory, const std::string& newBuildCommand, const std::string& newRunCommand);
            static void remove(const std::string& name);
    };
}