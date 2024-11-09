#pragma once

#include <vector>
#include "Triangle.h"
#include "units/Angle.h"
#include "units/Coordinate.h"

namespace mms_backend {
    class Polygon {
        public:
            Polygon();
            Polygon(const Polygon& polygon);
            Polygon(const std::vector<Coordinate>& vertices);

            std::vector<Coordinate> getVertices() const;
            std::vector<Triangle> getTriangles() const;

            Polygon translate(const Coordinate& translation) const;
            Polygon rotateAroundPoint(const Angle& angle, const Coordinate& point) const;

        private:
            std::vector<Coordinate> m_vertices;

            // Mutable allows lazy initialization
            mutable std::vector<Triangle> m_triangles;

            // Private constructor to avoid unnecessary re-triangulation
            Polygon(const std::vector<Coordinate>& vertices, const std::vector<Triangle>& triangles);

            bool alreadyPerformedTriangulation() const;
            static std::vector<Triangle> triangulate(const std::vector<Coordinate>& vertices);
    };
}