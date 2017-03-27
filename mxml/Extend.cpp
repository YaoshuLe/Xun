#include "Extend.h"
#include <cstring>

namespace mxml
{
  Extend::Extend() {}
  bool Extend::hasType() const { return _hasType; }
  void Extend::hasType(bool value) { _hasType = value; }
  StartStopContinueEnum Extend::type() const { return _type; }
  void Extend::type(StartStopContinueEnum value) { _type = value; }

  void Extend::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
  }
  void Extend::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = StartStopContinueEnum(attr.as_string());
      _hasType = true;
    }
  }
}
