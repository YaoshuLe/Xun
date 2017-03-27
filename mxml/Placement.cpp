#include "Placement.h"
#include <cstring>

namespace mxml
{
  Placement::Placement() {}
  bool Placement::hasPlacement() const { return _hasPlacement; }
  void Placement::hasPlacement(bool value) { _hasPlacement = value; }
  AboveBelowEnum Placement::placement() const { return _placement; }
  void Placement::placement(AboveBelowEnum value) { _placement = value; }

  void Placement::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasPlacement) {
      self.append_attribute("placement").set_value(_placement.operator const char *());
    }
  }
  void Placement::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("placement")) {
      _placement = AboveBelowEnum(attr.as_string());
      _hasPlacement = true;
    }
  }
}
