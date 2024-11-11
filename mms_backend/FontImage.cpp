#include "FontImage.h"

namespace mms {

std::string FontImage::path() {
    return "../resources/fonts/Unispace-Bold.png";
}

// Returns a string of all characters available in the font image
// Must match the font image, else the wrong characters will be displayed on the tiles
std::string FontImage::characters() {
    return " !\"#$%&'()*+,-./0123456789:;<=>?"
           "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
           "`abcdefghijklmnopqrstuvwxyz{|}~";
}

// Returns a map of character positions in the font image
std::map<char, std::pair<double, double>> FontImage::positions() {
    static std::map<char, std::pair<double, double>> map;
    if (map.empty()) {
        // Map from char to fractional position in the image (from 0.0 to 1.0)
        std::string chars = characters();
        int size = chars.size();
        for (int i = 0; i < size; i++) {
            double start = static_cast<double>(i) / size;
            double end = static_cast<double>(i + 1) / size;
            map[chars[i]] = {start, end};
        }
    }
    return map;
}

} 
