#include "Barre.h"
#include <cstring>

namespace mxml
{
  Barre::Barre() {}
  bool Barre::hasType() const { return _hasType; }
  void Barre::hasType(bool value) { _hasType = value; }
  StartStopEnum Barre::type() const { return _type; }
  void Barre::type(StartStopEnum value) { _type = value; }

  void Barre::ostreamAttrs(pugi::xml_node& self) const
  {
    Color::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
  }
  void Barre::istreamAttrs(const pugi::xml_node& self)
  {
    Color::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = StartStopEnum(attr.as_string());
      _hasType = true;
    }
  }
}
