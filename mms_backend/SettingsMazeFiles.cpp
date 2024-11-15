#include <SettingsMazeFiles.h>
#include <Settings.h>

namespace mms_backend{
    const std::string SettingsMazeFiles::GROUP = "maze_files";
    const std::string SettingsMazeFiles::KEY_PATH = "path";

    std::vector<std::string> SettingsMazeFiles::getAllPaths() {
        return Settings::get()->values(GROUP, KEY_PATH);
    }

    void SettingsMazeFiles::addPath(const std::string& path) {
        if (Settings::get()->find(GROUP, KEY_PATH, path).empty())
        {
            Settings::get()->add(GROUP, {{KEY_PATH, path}});
        } 
    }

    void SettingsMazeFiles::removePath(const std::string& path) {
        Settings::get()->remove(GROUP, KEY_PATH, path);
    }
}