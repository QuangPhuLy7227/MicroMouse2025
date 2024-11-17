#pragma once

#include <string>

namespace mms_backend {

class ConfigDialog {
 public:
  ConfigDialog(std::string name, std::string directory, std::string buildCommand,
               std::string runCommand);

  std::string getName();
  std::string getDirectory();
  std::string getBuildCommand();
  std::string getRunCommand();
  bool removeButtonPressed();

 private:
  std::string m_name;
  std::string m_directory;
  std::string m_buildCommand;
  std::string m_runCommand;
  bool m_removeButtonPressed;

//   void onBrowseButtonPressed();
//   void onRemoveButtonPressed();
//   void validate(std::string name);
};

}  
