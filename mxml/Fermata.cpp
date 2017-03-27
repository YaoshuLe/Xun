#include "Fermata.h"
#include <cstring>

namespace mxml
{
  Fermata::Fermata() {}
  bool Fermata::hasType() const { return _hasType; }
  void Fermata::hasType(bool value) { _hasType = value; }
  UprightInvertedEnum Fermata::type() const { return _type; }
  void Fermata::type(UprightInvertedEnum value) { _type = value; }

  void Fermata::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
  }
  void Fermata::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = UprightInvertedEnum(attr.as_string());
      _hasType = true;
    }
  }
}
