#include "SettingsMisc.h"
#include "Settings.h"

namespace mms_backend {
    // const std::string SettingsMisc::GROUP = "misc";
    // const std::string SettingsMisc::KEY_RECENT_MAZE_ALGO = "recent-maze-file";
    // const std::string SettingsMisc::KEY_RECENT_MOUSE_ALGO = "recent-mouse-algo";
    // const std::string SettingsMisc::KEY_RECENT_WINDOW_WIDTH = "recent-window-width";
    // const std::string SettingsMisc::KEY_RECENT_WINDOW_HEIGHT = "recent-window-height";

    std::string SettingsMisc::getRecentMazeFile() {
        return Settings::get()->value("misc", "recent_maze_file");
    }

    void SettingsMisc::setRecentMazeFile(const std::string& path) {
        Settings::get()->update("misc", "recent_maze_file", path);
    }

    std::string SettingsMisc::getRecentMouseAlgo() {
        return Settings::get()->value("misc", "recent_mouse_algo");
    }

    void SettingsMisc::setRecentMouseAlgo(const std::string& name) {
        Settings::get()->update("misc", "recent_mouse_algo", name);
    }

    int SettingsMisc::getRecentWindowWidth() {
        return std::stoi(Settings::get()->value("misc", "recent_window_width"));
    }

    void SettingsMisc::setRecentWindowWidth(int width) {
        Settings::get()->update("misc", "recent_window_width", std::to_string(width));
    }

    int SettingsMisc::getRecentWindowHeight() {
        return std::stoi(Settings::get()->value("misc", "recent_window_height"));
    }

    void SettingsMisc::setRecentWindowHeight(int height) {
        Settings::get()->update("misc", "recent_window_height", std::to_string(height));
    }

    // int SettingsMisc::getNumber(const std::string& key, int defaultValue) {
    //     bool ok = true;
    //     int number = std::stoi(Settings::get()->value("misc", key), &ok);
    //     if (!ok) {
    //         number = defaultValue;
    //         Settings::get()->update("misc", key, std::to_string(defaultValue));
    //     }
    //     return number;
    // }

    std::string SettingsMisc::getValue(const std::string& key) {
        return Settings::get()->value("misc", key);
    }

    void SettingsMisc::setValue(const std::string& key, const std::string& value) {
        Settings::get()->update("misc", key, value);
    }
}