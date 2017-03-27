#include "Valign.h"
#include <cstring>

namespace mxml
{
  Valign::Valign() {}
  bool Valign::hasValign() const { return _hasValign; }
  void Valign::hasValign(bool value) { _hasValign = value; }
  ValignEnum Valign::valign() const { return _valign; }
  void Valign::valign(ValignEnum value) { _valign = value; }

  void Valign::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasValign) {
      self.append_attribute("valign").set_value(_valign.operator const char *());
    }
  }
  void Valign::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("valign")) {
      _valign = ValignEnum(attr.as_string());
      _hasValign = true;
    }
  }
}
