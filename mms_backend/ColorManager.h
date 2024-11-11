#pragma once

#include "Color.h"

namespace mms_backend {

class ColorManager {
 public:
  static void init();
  static ColorManager* get();

  Color getTileBaseColor();
  Color getTileWallColor();
  Color getTileCornerColor();
  Color getMouseBodyColor();
  Color getMouseWheelColor();
  Color getTileWallIsSetColor();
  unsigned char getTileWallNotSetAlpha();

  void update(Color tileBaseColor, Color tileWallColor, Color mouseBodyColor,
              Color mouseWheelColor, Color tileWallIsSetColor,
              unsigned char tileWallNotSetAlpha);

 private:
  ColorManager();
  static ColorManager* INSTANCE;

  char getKeyForColor(Color color);

  Color m_tileBaseColor;
  Color m_tileWallColor;
  Color m_tileCornerColor;
  Color m_mouseBodyColor;
  Color m_mouseWheelColor;
  // Override tile colors when algo is running
  Color m_tileWallIsSetColor;
  unsigned char m_tileWallNotSetAlpha;

  static const std::string GROUP;
  static const std::string KEY_TILE_BASE_COLOR;
  static const std::string KEY_TILE_WALL_COLOR;
  static const std::string KEY_TILE_CORNER_COLOR;
  static const std::string KEY_MOUSE_BODY_COLOR;
  static const std::string KEY_MOUSE_WHEEL_COLOR;
  static const std::string KEY_TILE_WALL_IS_SET_COLOR;
  static const std::string KEY_TILE_WALL_NOT_SET_ALPHA;

  static Color getColor(const std::string& key, Color defaultValue);
  static unsigned char getNumber(const std::string& key, unsigned char defaultValue);
  static void setValue(const std::string& key, const std::string& value);
};

}