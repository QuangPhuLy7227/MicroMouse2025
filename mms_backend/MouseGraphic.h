#pragma once

#include <vector>
#include "Mouse.h"
#include "TriangleGraphic.h"
#include "ColorManager.h"
#include "SimUtilities.h"

namespace mms_backend {
    class MouseGraphic {
        public:
            MouseGraphic(const Mouse* mouse);
            std::vector<TriangleGraphic> draw() const;

        private:
            const Mouse* m_mouse;
    };
}