#pragma once
#include <string>

namespace mms_backend {
    class SettingsMisc {
        public:
            SettingsMisc() = delete;
            static std::string getRecentMazeFile();
            static void setRecentMazeFile(const std::string& path);

            static std::string getRecentMouseAlgo();
            static void setRecentMouseAlgo(const std::string& name);

            static int getRecentWindowWidth();
            static void setRecentWindowWidth(int width);

            static int getRecentWindowHeight();
            static void setRecentWindowHeight(int height);

        private:
            // static const std::string GROUP;
            // // static const std::string KEY_RECENT_MAZE_FILE;
            // static const std::string KEY_RECENT_MAZE_ALGO;
            // static const std::string KEY_RECENT_MOUSE_ALGO;
            // static const std::string KEY_RECENT_WINDOW_WIDTH;
            // static const std::string KEY_RECENT_WINDOW_HEIGHT;

            static int getNumber(const std::string& key, int defaultValue);
            static std::string getValue(const std::string& key);
            static void setValue(const std::string& key, const std::string& value);
    };
}