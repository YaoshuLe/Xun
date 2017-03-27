#include "StringMute.h"
#include <cstring>

namespace mxml
{
  StringMute::StringMute() {}
  bool StringMute::hasType() const { return _hasType; }
  void StringMute::hasType(bool value) { _hasType = value; }
  OnOffEnum StringMute::type() const { return _type; }
  void StringMute::type(OnOffEnum value) { _type = value; }

  void StringMute::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyleAlign::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
  }
  void StringMute::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyleAlign::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = OnOffEnum(attr.as_string());
      _hasType = true;
    }
  }
}
