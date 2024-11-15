#include "SettingsMouseAlgos.h"
#include "Settings.h"

namespace mms_backend {
    std::vector<std::string> SettingsMouseAlgos::names() {
        return Settings::get()->values("mouse_algos", "name");
    }

    std::string SettingsMouseAlgos::getDirectory(const std::string& name) {
        return Settings::get()->value("mouse_algos", name + "_directory");
    }

    std::string SettingsMouseAlgos::getBuildCommand(const std::string& name) {
        return Settings::get()->value("mouse_algos", name + "_build_command");
    }

    std::string SettingsMouseAlgos::getRunCommand(const std::string& name) {
        return Settings::get()->value("mouse_algos", name + "_run_command");
    }

    void SettingsMouseAlgos::add(const std::string& name, const std::string& directory,
                                const std::string& buildCommand, const std::string& runCommand) {
        Settings::get()->add("mouse_algos", {
            {"name", name},
            {"directory", directory},
            {"build_command", buildCommand},
            {"run_command", runCommand}
        });
    }

    void SettingsMouseAlgos::update(const std::string& name, const std::string& newName,
                                    const std::string& newDirectory, const std::string& newBuildCommand,
                                    const std::string& newRunCommand) {
        Settings::get()->update("mouse_algos", "name", name, {
            {"name", newName},
            {"directory", newDirectory},
            {"build_command", newBuildCommand},
            {"run_command", newRunCommand}
        });
    }

    void SettingsMouseAlgos::remove(const std::string& name) {
        Settings::get()->remove("mouse_algos", "name", name);
    }
}