#include "ColorDialog.h"

namespace mms_backend {

ColorDialog::ColorDialog(char tileBaseColor, char tileWallColor,
                         char mouseBodyColor, char mouseWheelColor,
                         char tileWallIsSetColor,
                         unsigned char tileWallNotSetAlpha)
    : m_tileBaseColor(tileBaseColor), m_tileWallColor(tileWallColor),
      m_mouseBodyColor(mouseBodyColor), m_mouseWheelColor(mouseWheelColor),
      m_tileWallIsSetColor(tileWallIsSetColor),
      m_tileWallNotSetAlpha(tileWallNotSetAlpha) {}

char ColorDialog::getTileBaseColor() const { return m_tileBaseColor; }
char ColorDialog::getTileWallColor() const { return m_tileWallColor; }
char ColorDialog::getMouseBodyColor() const { return m_mouseBodyColor; }
char ColorDialog::getMouseWheelColor() const { return m_mouseWheelColor; }
char ColorDialog::getTileWallIsSetColor() const { return m_tileWallIsSetColor; }
unsigned char ColorDialog::getTileWallNotSetAlpha() const { return m_tileWallNotSetAlpha; }

void ColorDialog::setColors(char tileBaseColor, char tileWallColor, char mouseBodyColor,
                            char mouseWheelColor, char tileWallIsSetColor,
                            unsigned char tileWallNotSetAlpha) {
    m_tileBaseColor = tileBaseColor;
    m_tileWallColor = tileWallColor;
    m_mouseBodyColor = mouseBodyColor;
    m_mouseWheelColor = mouseWheelColor;
    m_tileWallIsSetColor = tileWallIsSetColor;
    m_tileWallNotSetAlpha = tileWallNotSetAlpha;
}

} 
