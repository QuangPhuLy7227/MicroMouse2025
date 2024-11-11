#include "ColorManager.h"

#include "AssertMacros.h"
#include "Color.h"
#include "Settings.h"

namespace mms_backend {

const std::string ColorManager::GROUP = "colors";
const std::string ColorManager::KEY_TILE_BASE_COLOR = "mouse-base-color";
const std::string ColorManager::KEY_TILE_WALL_COLOR = "mouse-wall-color";
const std::string ColorManager::KEY_TILE_CORNER_COLOR = "mouse-corner-color";
const std::string ColorManager::KEY_MOUSE_BODY_COLOR = "mouse-body-color";
const std::string ColorManager::KEY_MOUSE_WHEEL_COLOR = "mouse-wheel-color";
const std::string ColorManager::KEY_TILE_WALL_IS_SET_COLOR = "tile-wall-is-set-color";
const std::string ColorManager::KEY_TILE_WALL_NOT_SET_ALPHA = "tile-wall-not-set-alpha";

ColorManager* ColorManager::INSTANCE = nullptr;

void ColorManager::init() {
    if (INSTANCE == nullptr) {
        INSTANCE = new ColorManager();
    }
}

ColorManager* ColorManager::get() {
    return INSTANCE;
}

Color ColorManager::getTileBaseColor() { return m_tileBaseColor; }

Color ColorManager::getTileWallColor() { return m_tileWallColor; }

Color ColorManager::getTileCornerColor() { return m_tileCornerColor; }

Color ColorManager::getMouseBodyColor() { return m_mouseBodyColor; }

Color ColorManager::getMouseWheelColor() { return m_mouseWheelColor; }

Color ColorManager::getTileWallIsSetColor() { return m_tileWallIsSetColor; }

unsigned char ColorManager::getTileWallNotSetAlpha() {
    return m_tileWallNotSetAlpha;
}

void ColorManager::update(Color tileBaseColor, Color tileWallColor,
                          Color mouseBodyColor, Color mouseWheelColor,
                          Color tileWallIsSetColor,
                          unsigned char tileWallNotSetAlpha) {
    m_tileBaseColor = tileBaseColor;
    m_tileWallColor = tileWallColor;
    m_mouseBodyColor = mouseBodyColor;
    m_mouseWheelColor = mouseWheelColor;
    m_tileWallIsSetColor = tileWallIsSetColor;
    m_tileWallNotSetAlpha = tileWallNotSetAlpha;

    // Updated to use getKeyForColor to get the key for a Color value
    setValue(KEY_TILE_BASE_COLOR, std::string(1, getKeyForColor(tileBaseColor)));
    setValue(KEY_TILE_WALL_COLOR, std::string(1, getKeyForColor(tileWallColor)));
    setValue(KEY_MOUSE_BODY_COLOR, std::string(1, getKeyForColor(mouseBodyColor)));
    setValue(KEY_MOUSE_WHEEL_COLOR, std::string(1, getKeyForColor(mouseWheelColor)));
    setValue(KEY_TILE_WALL_IS_SET_COLOR, std::string(1, getKeyForColor(tileWallIsSetColor)));
    setValue(KEY_TILE_WALL_NOT_SET_ALPHA, std::to_string(tileWallNotSetAlpha));
}

ColorManager::ColorManager()
    : m_tileBaseColor(getColor(KEY_TILE_BASE_COLOR, Color::BLACK)),
      m_tileWallColor(getColor(KEY_TILE_WALL_COLOR, Color::RED)),
      m_tileCornerColor(getColor(KEY_TILE_CORNER_COLOR, Color::GRAY)),
      m_mouseBodyColor(getColor(KEY_MOUSE_BODY_COLOR, Color::BLUE)),
      m_mouseWheelColor(getColor(KEY_MOUSE_WHEEL_COLOR, Color::GREEN)),
      m_tileWallIsSetColor(getColor(KEY_TILE_WALL_IS_SET_COLOR, Color::RED)),
      m_tileWallNotSetAlpha(getNumber(KEY_TILE_WALL_NOT_SET_ALPHA, 64)) {}

Color ColorManager::getColor(const std::string& key, Color defaultValue) {
    std::string colorStr = Settings::get()->value(GROUP, key);
    if (colorStr.empty() || !CHAR_TO_COLOR().count(colorStr[0])) {
        setValue(key, std::string(1, ColorManager::get()->getKeyForColor(defaultValue)));
        return defaultValue;
    }
    return CHAR_TO_COLOR().at(colorStr[0]);
}

unsigned char ColorManager::getNumber(const std::string& key, unsigned char defaultValue) {
    std::string numberStr = Settings::get()->value(GROUP, key);
    unsigned char number = static_cast<unsigned char>(std::stoi(numberStr));
    return number;
}

void ColorManager::setValue(const std::string& key, const std::string& value) {
    Settings::get()->update(GROUP, key, value);
}

// Helper function to find the key for a Color 
char ColorManager::getKeyForColor(Color color) {
    for (const auto& pair : CHAR_TO_COLOR()) {
        if (pair.second == color) {  
            return pair.first;  
        }
    }
    return '\0';  
}

}
