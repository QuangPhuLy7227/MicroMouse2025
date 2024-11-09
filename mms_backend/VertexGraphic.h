#pragma once
#include "RGB.h"

namespace mms_backend {
    struct VertexGraphic {
        float x;          // x position
        float y;          // y position
        RGB rgb;          // rgb values
        unsigned char a;  // alpha value
    };
}