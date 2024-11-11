#include "Direction.h"

namespace mms_backend {

    const std::vector<Direction>& CARDINAL_DIRECTIONS() {
        static const std::vector<Direction> vector = {
            Direction::North,
            Direction::East,
            Direction::South,
            Direction::West,
        };
        return vector;
    }

    const std::vector<SemiDirection>& ORDINAL_DIRECTIONS() {
        static const std::vector<SemiDirection> vector = {
            SemiDirection::NORTHEAST,
            SemiDirection::NORTHWEST,
            SemiDirection::SOUTHEAST,
            SemiDirection::SOUTHWEST,
        };
        return vector;
    }

    const std::map<SemiDirection, Direction>& SEMI_TO_CARDINAL() {
        static const std::map<SemiDirection, Direction> map = {
            {SemiDirection::NORTH, Direction::North},
            {SemiDirection::SOUTH, Direction::South},
            {SemiDirection::EAST, Direction::East},
            {SemiDirection::WEST, Direction::West},
        };
        return map;
    }

    const std::map<SemiDirection, SemiDirection>& DIRECTION_ROTATE_45_LEFT() {
        static const std::map<SemiDirection, SemiDirection> map = {
            {SemiDirection::NORTH, SemiDirection::NORTHWEST},
            {SemiDirection::SOUTH, SemiDirection::SOUTHEAST},
            {SemiDirection::EAST, SemiDirection::NORTHEAST},
            {SemiDirection::WEST, SemiDirection::SOUTHWEST},
            {SemiDirection::NORTHEAST, SemiDirection::NORTH},
            {SemiDirection::NORTHWEST, SemiDirection::WEST},
            {SemiDirection::SOUTHEAST, SemiDirection::EAST},
            {SemiDirection::SOUTHWEST, SemiDirection::SOUTH},
        };
        return map;
    }

    const std::map<SemiDirection, SemiDirection>& DIRECTION_ROTATE_45_RIGHT() {
        static const std::map<SemiDirection, SemiDirection> map = {
            {SemiDirection::NORTH, SemiDirection::NORTHEAST},
            {SemiDirection::SOUTH, SemiDirection::SOUTHWEST},
            {SemiDirection::EAST, SemiDirection::SOUTHEAST},
            {SemiDirection::WEST, SemiDirection::NORTHWEST},
            {SemiDirection::NORTHEAST, SemiDirection::EAST},
            {SemiDirection::NORTHWEST, SemiDirection::NORTH},
            {SemiDirection::SOUTHEAST, SemiDirection::SOUTH},
            {SemiDirection::SOUTHWEST, SemiDirection::WEST},
        };
        return map;
    }

    const std::map<SemiDirection, SemiDirection>& DIRECTION_ROTATE_90_LEFT() {
        static const std::map<SemiDirection, SemiDirection> map = {
            {SemiDirection::NORTH, SemiDirection::WEST},
            {SemiDirection::SOUTH, SemiDirection::EAST},
            {SemiDirection::EAST, SemiDirection::NORTH},
            {SemiDirection::WEST, SemiDirection::SOUTH},
            {SemiDirection::NORTHEAST, SemiDirection::NORTHWEST},
            {SemiDirection::NORTHWEST, SemiDirection::SOUTHWEST},
            {SemiDirection::SOUTHEAST, SemiDirection::NORTHEAST},
            {SemiDirection::SOUTHWEST, SemiDirection::SOUTHEAST},
        };
        return map;
    }

    const std::map<SemiDirection, SemiDirection>& DIRECTION_ROTATE_90_RIGHT() {
        static const std::map<SemiDirection, SemiDirection> map = {
            {SemiDirection::NORTH, SemiDirection::EAST},
            {SemiDirection::SOUTH, SemiDirection::WEST},
            {SemiDirection::EAST, SemiDirection::SOUTH},
            {SemiDirection::WEST, SemiDirection::NORTH},
            {SemiDirection::NORTHEAST, SemiDirection::SOUTHEAST},
            {SemiDirection::NORTHWEST, SemiDirection::NORTHEAST},
            {SemiDirection::SOUTHEAST, SemiDirection::SOUTHWEST},
            {SemiDirection::SOUTHWEST, SemiDirection::NORTHWEST},
        };
        return map;
    }

    const std::map<SemiDirection, SemiDirection>& DIRECTION_ROTATE_180() {
        static const std::map<SemiDirection, SemiDirection> map = {
            {SemiDirection::NORTH, SemiDirection::SOUTH},
            {SemiDirection::SOUTH, SemiDirection::NORTH},
            {SemiDirection::EAST, SemiDirection::WEST},
            {SemiDirection::WEST, SemiDirection::EAST},
            {SemiDirection::NORTHEAST, SemiDirection::SOUTHWEST},
            {SemiDirection::NORTHWEST, SemiDirection::SOUTHEAST},
            {SemiDirection::SOUTHEAST, SemiDirection::NORTHWEST},
            {SemiDirection::SOUTHWEST, SemiDirection::NORTHEAST},
        };
        return map;
    }

    const std::map<char, Direction>& CHAR_TO_DIRECTION() {
        static const std::map<char, Direction> map = {
            {'n', Direction::North},
            {'e', Direction::East},
            {'s', Direction::South},
            {'w', Direction::West},
        };
        return map;
    }

    const std::map<SemiDirection, Angle>& DIRECTION_TO_ANGLE() {
        static const std::map<SemiDirection, Angle> map = {
            {SemiDirection::EAST, Angle::Degrees(0)},
            {SemiDirection::NORTHEAST, Angle::Degrees(45)},
            {SemiDirection::NORTH, Angle::Degrees(90)},
            {SemiDirection::NORTHWEST, Angle::Degrees(135)},
            {SemiDirection::WEST, Angle::Degrees(180)},
            {SemiDirection::SOUTHWEST, Angle::Degrees(225)},
            {SemiDirection::SOUTH, Angle::Degrees(270)},
            {SemiDirection::SOUTHEAST, Angle::Degrees(315)},
        };
        return map;
    }

} // namespace mms_backend
