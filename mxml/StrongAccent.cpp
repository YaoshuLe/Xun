#include "StrongAccent.h"
#include <cstring>

namespace mxml
{
  StrongAccent::StrongAccent() {}
  bool StrongAccent::hasType() const { return _hasType; }
  void StrongAccent::hasType(bool value) { _hasType = value; }
  UpDownEnum StrongAccent::type() const { return _type; }
  void StrongAccent::type(UpDownEnum value) { _type = value; }

  void StrongAccent::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
  }
  void StrongAccent::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = UpDownEnum(attr.as_string());
      _hasType = true;
    }
  }
}
