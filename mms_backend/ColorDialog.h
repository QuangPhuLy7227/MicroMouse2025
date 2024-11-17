#pragma once

namespace mms_backend {

class ColorDialog {
public:
    ColorDialog(char tileBaseColor, char tileWallColor, char mouseBodyColor,
                char mouseWheelColor, char tileWallIsSetColor,
                unsigned char tileWallNotSetAlpha);

    char getTileBaseColor() const;
    char getTileWallColor() const;
    char getMouseBodyColor() const;
    char getMouseWheelColor() const;
    char getTileWallIsSetColor() const;
    unsigned char getTileWallNotSetAlpha() const;

    void setColors(char tileBaseColor, char tileWallColor, char mouseBodyColor,
                   char mouseWheelColor, char tileWallIsSetColor,
                   unsigned char tileWallNotSetAlpha);

private:
    char m_tileBaseColor;
    char m_tileWallColor;
    char m_mouseBodyColor;
    char m_mouseWheelColor;
    char m_tileWallIsSetColor;
    unsigned char m_tileWallNotSetAlpha;
};

} 
