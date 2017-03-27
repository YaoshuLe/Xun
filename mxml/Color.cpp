#include "Color.h"
#include <cstring>

namespace mxml
{
  Color::Color() {}
  bool Color::hasColor() const { return _hasColor; }
  void Color::hasColor(bool value) { _hasColor = value; }
  std::string Color::color() const { return _color; }
  void Color::color(std::string value) { _color = value; }

  void Color::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasColor) {
      self.append_attribute("color").set_value(_color.c_str());
    }
  }
  void Color::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("color")) {
      _color = attr.as_string();
      _hasColor = true;
    }
  }
}
