#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <nlohmann/json.hpp>

namespace mms_backend {
    class Settings {
        public:
            static void init();
            static Settings* get();

            // Non-array functions
            std::string value(const std::string& group, const std::string& key);
            void update(const std::string& group, const std::string& key, const std::string& value);

            // Array-group functions
            std::vector<std::string> values(const std::string& group, const std::string& key);
            void add(const std::string& group, const std::unordered_map<std::string, std::string>& entry);
            void remove(const std::string& group, const std::string& key, const std::string& value);
            std::vector<std::unordered_map<std::string, std::string>> find(const std::string& group, const std::string& key, const std::string& value);
            void update(const std::string& group, const std::string& key, const std::string& value, const std::unordered_map<std::string, std::string>& changes);

        private:
            Settings();
            static Settings* INSTANCE;
            nlohmann::json settingsData;
            void loadSettings();
            void saveSettings();
    };
}