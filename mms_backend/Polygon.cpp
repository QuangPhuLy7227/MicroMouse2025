#include "Polygon.h"
#include "AssertMacros.h"
#include "GeometryUtilities.h"
#include "SimUtilities.h"
#include "polypartition/polypartition.h"
#include <cmath>
#include <list>

namespace mms_backend {
    Polygon::Polygon() {}
    Polygon::Polygon(const Polygon& polygon) : m_vertices(polygon.getVertices()) {
        // Copy triangles if already triangulated
        if (polygon.alreadyPerformedTriangulation()) {
            m_triangles = polygon.getTriangles();
        } else {

        }
    }

    // Postpone triangulation until we absolutely have to do it.
    Polygon::Polygon(const std::vector<Coordinate>& vertices) : m_vertices(vertices), m_triangles({}) {
        ASSERT_LE(3, m_vertices.size());

        // Simple triangulation for three vertices
        if (m_vertices.size() == 3) {
            m_triangles = {{
                m_vertices[0],
                m_vertices[1],
                m_vertices[2],
            }};
        }
    }

    std::vector<Coordinate> Polygon::getVertices() const { 
        return m_vertices; 
    }

    std::vector<Triangle> Polygon::getTriangles() const {
        // Lazy triangulation
        if (m_triangles.empty()) {
            m_triangles = triangulate(m_vertices);
        }
        return m_triangles;
    }

    Polygon Polygon::translate(const Coordinate& translation) const {
        std::vector<Coordinate> vertices;
        for (const auto& vertex : m_vertices) {
            vertices.push_back(GeometryUtilities::translateVertex(vertex, translation));
        }

        std::vector<Triangle> triangles;
        for (const auto& triangle : m_triangles) {
            triangles.push_back({
                GeometryUtilities::translateVertex(triangle.p1, translation),
                GeometryUtilities::translateVertex(triangle.p2, translation),
                GeometryUtilities::translateVertex(triangle.p3, translation),
            });
        }

        return Polygon(vertices, triangles);
    }

    Polygon Polygon::rotateAroundPoint(const Angle& angle, const Coordinate& point) const {
        std::vector<Coordinate> vertices;
        for (const auto& vertex : m_vertices) {
            vertices.push_back(GeometryUtilities::rotateVertexAroundPoint(vertex, point, angle));
        }

        std::vector<Triangle> triangles;
        for (const auto& triangle : m_triangles) {
            triangles.push_back({
                GeometryUtilities::rotateVertexAroundPoint(triangle.p1, point, angle),
                GeometryUtilities::rotateVertexAroundPoint(triangle.p2, point, angle),
                GeometryUtilities::rotateVertexAroundPoint(triangle.p3, point, angle),
            });
        }

        return Polygon(vertices, triangles);
    }

    Polygon::Polygon(const std::vector<Coordinate>& vertices, const std::vector<Triangle>& triangles) : m_vertices(vertices), m_triangles(triangles) {}

    bool Polygon::alreadyPerformedTriangulation() const {
        return !m_triangles.empty();
    }

    std::vector<Triangle> Polygon::triangulate(const std::vector<Coordinate>& vertices) {
        // Populate the TPPLPoly
        TPPLPoly tpplPoly;
        tpplPoly.Init(vertices.size());
        for (size_t i = 0; i < vertices.size(); ++i) {
            tpplPoly[i].x = vertices[i].getX().getMeters();
            tpplPoly[i].y = vertices[i].getY().getMeters();
        }
        tpplPoly.SetOrientation(TPPL_CCW);

        // Perform the triangulation
        TPPLPartition triangulator;
        std::list<TPPLPoly> result;
        triangulator.Triangulate_EC(&tpplPoly, &result);

        // Convert triangulation result to std::vector<Triangle>
        std::vector<Triangle> triangles;
        for (auto it = result.begin(); it != result.end(); it++) {
            triangles.push_back({
                Coordinate::Cartesian(Distance::Meters((*it)[0].x),
                                    Distance::Meters((*it)[0].y)),
                Coordinate::Cartesian(Distance::Meters((*it)[1].x),
                                    Distance::Meters((*it)[1].y)),
                Coordinate::Cartesian(Distance::Meters((*it)[2].x),
                                    Distance::Meters((*it)[2].y)),
            });
        }

        return triangles;
    }
}