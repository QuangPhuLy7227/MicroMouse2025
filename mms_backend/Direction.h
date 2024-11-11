#pragma once

#include <map>
#include <vector>

#include "units/Angle.h"

namespace mms_backend
{
    enum class Direction {
        North,
        East,
        South,
        West
    };

    enum class SemiDirection {
        NORTH,
        SOUTH,
        EAST,
        WEST,
        NORTHEAST,
        SOUTHEAST,
        NORTHWEST,
        SOUTHWEST,
    };

    // This vector serves two functions:
    // 1) A convenient way to enumerate through all of the directions
    // 2) Determines the location of wall information in the vertex buffer  
    const std::vector<Direction>& CARDINAL_DIRECTIONS();

    const std::vector<SemiDirection>& ORDINAL_DIRECTIONS();
    const std::map<SemiDirection, Direction>& SEMI_TO_CARDINAL();

    const std::map<SemiDirection, SemiDirection>& DIRECTION_ROTATE_45_LEFT();
    const std::map<SemiDirection, SemiDirection>& DIRECTION_ROTATE_45_RIGHT();
    const std::map<SemiDirection, SemiDirection>& DIRECTION_ROTATE_90_LEFT();
    const std::map<SemiDirection, SemiDirection>& DIRECTION_ROTATE_90_RIGHT();
    const std::map<SemiDirection, SemiDirection>& DIRECTION_ROTATE_180();

    const std::map<char, Direction>& CHAR_TO_DIRECTION();
    const std::map<SemiDirection, Angle>& DIRECTION_TO_ANGLE();

};
