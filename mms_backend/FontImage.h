#pragma once

#include <map>
#include <string>
#include <utility>

namespace mms {

class FontImage {
public:
    FontImage() = delete;

    static std::string path();
    static std::string characters();
    static std::map<char, std::pair<double, double>> positions();
};

}  
