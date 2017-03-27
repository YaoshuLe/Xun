#include "Orientation.h"
#include <cstring>

namespace mxml
{
  Orientation::Orientation() {}
  bool Orientation::hasOrientation() const { return _hasOrientation; }
  void Orientation::hasOrientation(bool value) { _hasOrientation = value; }
  OverUnderEnum Orientation::orientation() const { return _orientation; }
  void Orientation::orientation(OverUnderEnum value) { _orientation = value; }

  void Orientation::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasOrientation) {
      self.append_attribute("orientation").set_value(_orientation.operator const char *());
    }
  }
  void Orientation::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("orientation")) {
      _orientation = OverUnderEnum(attr.as_string());
      _hasOrientation = true;
    }
  }
}
