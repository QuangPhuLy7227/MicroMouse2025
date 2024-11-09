#pragma once

#include <unordered_map>
#include <string>
#include "RGB.h"

namespace mms_backend {
    enum class Color {
        BLACK,
        BLUE,
        CYAN,
        GRAY,
        GREEN,
        ORANGE,
        RED,
        WHITE,
        YELLOW,
        DARK_BLUE,
        DARK_CYAN,
        DARK_GRAY,
        DARK_GREEN,
        DARK_ORANGE,
        DARK_RED,
        DARK_VIOLET,
        DARK_YELLOW
    };

    const std::unordered_map<char, Color>& CHAR_TO_COLOR();
    const std::unordered_map<Color, RGB>& COLOR_TO_RGB();
}