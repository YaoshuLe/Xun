#include "TextDirection.h"
#include <cstring>

namespace mxml
{
  TextDirection::TextDirection() {}
  bool TextDirection::hasDir() const { return _hasDir; }
  void TextDirection::hasDir(bool value) { _hasDir = value; }
  TextDirectionEnum TextDirection::dir() const { return _dir; }
  void TextDirection::dir(TextDirectionEnum value) { _dir = value; }

  void TextDirection::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasDir) {
      self.append_attribute("dir").set_value(_dir.operator const char *());
    }
  }
  void TextDirection::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("dir")) {
      _dir = TextDirectionEnum(attr.as_string());
      _hasDir = true;
    }
  }
}
