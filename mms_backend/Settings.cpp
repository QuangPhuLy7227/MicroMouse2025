#include <Settings.h>
#include <fstream>
#include <stdexcept>

namespace mms_backend {
    //Singleton
    Settings* Settings::INSTANCE = nullptr;
    void Settings::init() {
        if (INSTANCE == nullptr) {
            INSTANCE = new Settings();
        }
    }

    Settings *Settings::get() {
        if (INSTANCE == nullptr) {
            throw std::runtime_error("Settings not initialized");
        }
        return INSTANCE;
    }

    Settings::Settings() {
        loadSettings();
    }

    void Settings::loadSettings() {
        std::ifstream file("settings.json");
        if (file.is_open()) {
            file >> settingsData;
            file.close();
        }
    }

    void Settings::saveSettings() {
        std::ofstream file("settings.json");
        file << settingsData.dump(4);
        file.close();
    }

    std::string Settings::value(const std::string& group, const std::string& key) {
        if (settingsData.contains(group) && settingsData[group].contains(key)) {
            return settingsData[group][key];
        }
        return "";
    }

    void Settings::update(const std::string& group, const std::string& key, const std::string& value) {
        settingsData[group][key] = value;
        saveSettings();
    }

    std::vector<std::string> Settings::values(const std::string& group, const std::string& key) {
        std::vector<std::string> result;
        if (settingsData.contains(group))
        {
            for (const auto& entry : settingsData[group]) {
                if (entry.contains(key)) {
                    result.push_back(entry[key]);
                }
            }
        }
        return result;
    }

    void Settings::add(const std::string& group, const std::unordered_map<std::string, std::string>& entry) {
        settingsData[group].push_back(entry);
        saveSettings();
    }

    void Settings::remove(const std::string& group, const std::string& key, const std::string& value) {
        if (settingsData.contains(group))
        {
            auto& entries = settingsData[group];
            entries.erase(std::remove_if(entries.begin(), entries.end(), [&key, &value](const auto& entry) {
                return entry[key] == value;
            }), entries.end());
            saveSettings();
        }
    }

    std::vector<std::unordered_map<std::string, std::string>> Settings::find(const std::string& group, const std::string& key, const std::string& value) {
        std::vector<std::unordered_map<std::string, std::string>> result;
        if (settingsData.contains(group)) {
            for (const auto& entry : settingsData[group]) {
                if (entry.contains(key) && entry[key] == value) {
                    result.push_back(entry);
                }
            }
        }
        return result;
    }
}