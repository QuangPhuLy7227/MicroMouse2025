#include "SimUtilities.h"
#include "AssertMacros.h"
#include <chrono>

namespace mms_backend {
    double SimUtilities::getHighResTimestamp() {
        using namespace std::chrono;
        auto now = high_resolution_clock::now();
        return duration_cast<microseconds>(now.time_since_epoch()).count() / 1'000'000.0;
    }

    std::vector<TriangleGraphic> SimUtilities::polygonToTriangleGraphics(const Polygon& polygon, Color color, unsigned char alpha) {
        std::vector<Triangle> triangles = polygon.getTriangles();
        std::vector<TriangleGraphic> triangleGraphics;
        RGB colorValues = COLOR_TO_RGB().at(color);

        for (const Triangle& triangle : triangles) {
            TriangleGraphic graphic;
            graphic.p1 = {
                static_cast<float>(triangle.p1.getX().getMeters()),
                static_cast<float>(triangle.p1.getY().getMeters()),
                colorValues,
                alpha
            };
            graphic.p2 = {
                static_cast<float>(triangle.p2.getX().getMeters()),
                static_cast<float>(triangle.p2.getY().getMeters()),
                colorValues,
                alpha
            };
            graphic.p3 = {
                static_cast<float>(triangle.p3.getX().getMeters()),
                static_cast<float>(triangle.p3.getY().getMeters()),
                colorValues,
                alpha
            };
            triangleGraphics.push_back(graphic);
        }
        return triangleGraphics;
    }
}