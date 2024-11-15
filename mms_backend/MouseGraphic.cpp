#include "MouseGraphic.h"

namespace mms_backend {
    MouseGraphic::MouseGraphic(const Mouse* mouse) : m_mouse(mouse) {}

    std::vector<TriangleGraphic> MouseGraphic::draw() const {
        std::vector<TriangleGraphic> buffer;

        auto wheelGraphics = SimUtilities::polygonToTriangleGraphics(
            m_mouse->getCurrentWheelPolygon(),
            ColorManager::get()->getMouseWheelColor(),
            255
        );
        buffer.insert(buffer.end(), wheelGraphics.begin(), wheelGraphics.end());

        auto bodyGraphics = SimUtilities::polygonToTriangleGraphics(
            m_mouse->getCurrentBodyPolygon(),
            ColorManager::get()->getMouseBodyColor(),
            255
        );
        buffer.insert(buffer.end(), bodyGraphics.begin(), bodyGraphics.end());

        return buffer;
    }
}