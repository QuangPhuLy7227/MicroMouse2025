#include <Mouse.h>
#include "AssertMacros.h"
#include "Dimensions.h"
#include "GeometryUtilities.h"
#include "units/Distance.h"
#include <cmath>

namespace mms_backend {
    std::pair<int, int> SemiPosition::toMazeLocation() {
        return {x / 2, y / 2};
    }

    Mouse::Mouse() {
        Distance halfOfTileDistance = Dimensions::halfTileLength();
        m_initialTranslation = Coordinate::Cartesian(halfOfTileDistance, halfOfTileDistance);
        m_currentTranslation = m_initialTranslation;

        m_initialRotation = DIRECTION_TO_ANGLE().at(SemiDirection::NORTH);
        m_currentRotation = m_initialRotation;

        std::vector<Coordinate> bodyVertices = {
            Coordinate::Cartesian(Distance::Meters(0.00), Distance::Meters(0.00)),
            Coordinate::Cartesian(Distance::Meters(0.00), Distance::Meters(0.06)),
            Coordinate::Cartesian(Distance::Meters(0.03), Distance::Meters(0.09)),
            Coordinate::Cartesian(Distance::Meters(0.06), Distance::Meters(0.06)),
            Coordinate::Cartesian(Distance::Meters(0.06), Distance::Meters(0.00)),
        };

        Coordinate centerOfMass = Coordinate::Cartesian(Distance::Meters(0.06), Distance::Meters(0.06));
        for (auto& vertex : bodyVertices) {
            vertex = GeometryUtilities::translateVertex(vertex, centerOfMass);
        }
        m_initialBodyPolygon = Polygon(bodyVertices);
        std::vector<Coordinate> wheelVertices = {
            Coordinate::Cartesian(Distance::Meters(-0.005), Distance::Meters(0.01)),
            Coordinate::Cartesian(Distance::Meters(-0.005), Distance::Meters(0.05)),
            Coordinate::Cartesian(Distance::Meters(0.065), Distance::Meters(0.05)),
            Coordinate::Cartesian(Distance::Meters(0.065), Distance::Meters(0.01)),
        };
        for (auto& vertex : wheelVertices) {
            vertex = GeometryUtilities::translateVertex(vertex, centerOfMass);
        }
        m_initialWheelPolygon = Polygon(wheelVertices);

        m_initialBodyPolygon.getTriangles();
        m_initialWheelPolygon.getTriangles();
    }

    void Mouse::reset() {
        teleport(m_initialTranslation, DIRECTION_TO_ANGLE().at(SemiDirection::NORTH));
    }

    void Mouse::teleport(const Coordinate& translation, const Angle& rotation) {
        m_currentTranslation = translation;
        m_currentRotation = rotation;
    }

    SemiPosition Mouse::getCurrentDiscretizedTranslation() const {
        Distance halfTileLength = Dimensions::halfTileLength();
        Distance quarterTileLength = Dimensions::quarterTileLength();
        int x = static_cast<int>(std::floor((m_currentTranslation.getX() + quarterTileLength) / halfTileLength));
        int y = static_cast<int>(std::floor((m_currentTranslation.getY() + quarterTileLength) / halfTileLength));
        return {x, y};
    }

    SemiDirection Mouse::getCurrentDiscretizedRotation() const {
        int dir = static_cast<int>(std::floor((m_currentRotation + Angle::Degrees(22.5)).getRadiansZeroTo2pi() / Angle::Degrees(45).getRadiansZeroTo2pi()));
        switch (dir) {
            case 0: return SemiDirection::EAST;
            case 1: return SemiDirection::NORTHEAST;
            case 2: return SemiDirection::NORTH;
            case 3: return SemiDirection::NORTHWEST;
            case 4: return SemiDirection::WEST;
            case 5: return SemiDirection::SOUTHWEST;
            case 6: return SemiDirection::SOUTH;
            case 7: return SemiDirection::SOUTHEAST;
            default: ASSERT_NEVER_RUNS();
        }
    }

    Polygon Mouse::getCurrentBodyPolygon() const {
        return getCurrentPolygon(m_initialBodyPolygon);
    }

    Polygon Mouse::getCurrentWheelPolygon() const {
        return getCurrentPolygon(m_initialWheelPolygon);
    }

    Polygon Mouse::getCurrentPolygon(const Polygon& initialPolygon) const {
        return initialPolygon.translate(m_currentTranslation - m_initialTranslation)
            .rotateAroundPoint(m_currentRotation - m_initialRotation, m_currentTranslation);
    }
}