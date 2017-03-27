#include "BassAlter.h"
#include <cstring>

namespace mxml
{
  BassAlter::BassAlter() {}
  bool BassAlter::hasLocation() const { return _hasLocation; }
  void BassAlter::hasLocation(bool value) { _hasLocation = value; }
  LeftRightEnum BassAlter::location() const { return _location; }
  void BassAlter::location(LeftRightEnum value) { _location = value; }

  void BassAlter::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintObject::ostreamAttrs(self);
    PrintStyle::ostreamAttrs(self);
    if(_hasLocation) {
      self.append_attribute("location").set_value(_location.operator const char *());
    }
  }
  void BassAlter::istreamAttrs(const pugi::xml_node& self)
  {
    PrintObject::istreamAttrs(self);
    PrintStyle::istreamAttrs(self);
    if(auto attr = self.attribute("location")) {
      _location = LeftRightEnum(attr.as_string());
      _hasLocation = true;
    }
  }
}
