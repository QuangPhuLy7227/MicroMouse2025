#include <iostream>
#include <string>
#include "ConfigDialog.h"

namespace mms_backend {

ConfigDialog::ConfigDialog(std::string name, std::string directory,
                           std::string buildCommand, std::string runCommand)
    : m_name(name),
      m_directory(directory),
      m_buildCommand(buildCommand),
      m_runCommand(runCommand),
      m_removeButtonPressed(false) {}

std::string ConfigDialog::getName() { return m_name; }
std::string ConfigDialog::getDirectory() { return m_directory; }
std::string ConfigDialog::getBuildCommand() { return m_buildCommand; }
std::string ConfigDialog::getRunCommand() { return m_runCommand; }

bool ConfigDialog::removeButtonPressed() { return m_removeButtonPressed; }

}  
