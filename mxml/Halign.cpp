#include "Halign.h"
#include <cstring>

namespace mxml
{
  Halign::Halign() {}
  bool Halign::hasHalign() const { return _hasHalign; }
  void Halign::hasHalign(bool value) { _hasHalign = value; }
  LeftCenterRightEnum Halign::halign() const { return _halign; }
  void Halign::halign(LeftCenterRightEnum value) { _halign = value; }

  void Halign::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasHalign) {
      self.append_attribute("halign").set_value(_halign.operator const char *());
    }
  }
  void Halign::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("halign")) {
      _halign = LeftCenterRightEnum(attr.as_string());
      _hasHalign = true;
    }
  }
}
