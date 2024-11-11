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
}