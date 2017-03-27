#include "Cancel.h"
#include <cstring>

namespace mxml
{
  Cancel::Cancel() {}
  bool Cancel::hasLocation() const { return _hasLocation; }
  void Cancel::hasLocation(bool value) { _hasLocation = value; }
  CancelLocationEnum Cancel::location() const { return _location; }
  void Cancel::location(CancelLocationEnum value) { _location = value; }

  void Cancel::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasLocation) {
      self.append_attribute("location").set_value(_location.operator const char *());
    }
  }
  void Cancel::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("location")) {
      _location = CancelLocationEnum(attr.as_string());
      _hasLocation = true;
    }
  }
}
