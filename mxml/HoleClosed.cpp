#include "HoleClosed.h"
#include <cstring>

namespace mxml
{
  HoleClosed::HoleClosed() {}
  bool HoleClosed::hasLocation() const { return _hasLocation; }
  void HoleClosed::hasLocation(bool value) { _hasLocation = value; }
  HoleClosedLocationEnum HoleClosed::location() const { return _location; }
  void HoleClosed::location(HoleClosedLocationEnum value) { _location = value; }

  void HoleClosed::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasLocation) {
      self.append_attribute("location").set_value(_location.operator const char *());
    }
  }
  void HoleClosed::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("location")) {
      _location = HoleClosedLocationEnum(attr.as_string());
      _hasLocation = true;
    }
  }
}
