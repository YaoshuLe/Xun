#include "FirstFret.h"
#include <cstring>

namespace mxml
{
  FirstFret::FirstFret() {}
  bool FirstFret::hasText() const { return _hasText; }
  void FirstFret::hasText(bool value) { _hasText = value; }
  std::string FirstFret::text() const { return _text; }
  void FirstFret::text(std::string value) { _text = value; }
  bool FirstFret::hasLocation() const { return _hasLocation; }
  void FirstFret::hasLocation(bool value) { _hasLocation = value; }
  LeftRightEnum FirstFret::location() const { return _location; }
  void FirstFret::location(LeftRightEnum value) { _location = value; }

  void FirstFret::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasText) {
      self.append_attribute("text").set_value(_text.c_str());
    }
    if(_hasLocation) {
      self.append_attribute("location").set_value(_location.operator const char *());
    }
  }
  void FirstFret::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("text")) {
      _text = attr.as_string();
      _hasText = true;
    }
    if(auto attr = self.attribute("location")) {
      _location = LeftRightEnum(attr.as_string());
      _hasLocation = true;
    }
  }
}
