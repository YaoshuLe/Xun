#include "RootAlter.h"
#include <cstring>

namespace mxml
{
  RootAlter::RootAlter() {}
  bool RootAlter::hasLocation() const { return _hasLocation; }
  void RootAlter::hasLocation(bool value) { _hasLocation = value; }
  LeftRightEnum RootAlter::location() const { return _location; }
  void RootAlter::location(LeftRightEnum value) { _location = value; }

  void RootAlter::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintObject::ostreamAttrs(self);
    PrintStyle::ostreamAttrs(self);
    if(_hasLocation) {
      self.append_attribute("location").set_value(_location.operator const char *());
    }
  }
  void RootAlter::istreamAttrs(const pugi::xml_node& self)
  {
    PrintObject::istreamAttrs(self);
    PrintStyle::istreamAttrs(self);
    if(auto attr = self.attribute("location")) {
      _location = LeftRightEnum(attr.as_string());
      _hasLocation = true;
    }
  }
}
