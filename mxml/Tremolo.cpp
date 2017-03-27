#include "Tremolo.h"
#include <cstring>

namespace mxml
{
  Tremolo::Tremolo() {}
  bool Tremolo::hasType() const { return _hasType; }
  void Tremolo::hasType(bool value) { _hasType = value; }
  StartStopSingleEnum Tremolo::type() const { return _type; }
  void Tremolo::type(StartStopSingleEnum value) { _type = value; }

  void Tremolo::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
  }
  void Tremolo::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = StartStopSingleEnum(attr.as_string());
      _hasType = true;
    }
  }
}
