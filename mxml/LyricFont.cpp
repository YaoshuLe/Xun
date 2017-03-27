#include "LyricFont.h"
#include <cstring>

namespace mxml
{
  LyricFont::LyricFont() {}
  bool LyricFont::hasNumber() const { return _hasNumber; }
  void LyricFont::hasNumber(bool value) { _hasNumber = value; }
  std::string LyricFont::number() const { return _number; }
  void LyricFont::number(std::string value) { _number = value; }
  bool LyricFont::hasName() const { return _hasName; }
  void LyricFont::hasName(bool value) { _hasName = value; }
  std::string LyricFont::name() const { return _name; }
  void LyricFont::name(std::string value) { _name = value; }

  void LyricFont::ostreamAttrs(pugi::xml_node& self) const
  {
    Font::ostreamAttrs(self);
    if(_hasNumber) {
      self.append_attribute("number").set_value(_number.c_str());
    }
    if(_hasName) {
      self.append_attribute("name").set_value(_name.c_str());
    }
  }
  void LyricFont::istreamAttrs(const pugi::xml_node& self)
  {
    Font::istreamAttrs(self);
    if(auto attr = self.attribute("number")) {
      _number = attr.as_string();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("name")) {
      _name = attr.as_string();
      _hasName = true;
    }
  }
}
