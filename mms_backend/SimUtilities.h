#pragma once

#include <string>
#include <vector>
#include "Color.h"
#include "Polygon.h"
#include "TriangleGraphic.h"

namespace mms_backend {
    class SimUtilities {
        public:
            SimUtilities() = delete;
            // Like time() in <ctime> but higher resolution (returns seconds since epoch)
            static double getHighResTimestamp();
            // Converts a polygon to a vector of triangle graphics
            static std::vector<TriangleGraphic> polygonToTriangleGraphics(const Polygon& polygon, Color color, unsigned char alpha);
    };
}