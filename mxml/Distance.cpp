#include "Distance.h"
#include <cstring>

namespace mxml
{
  Distance::Distance() {}
  bool Distance::hasType() const { return _hasType; }
  void Distance::hasType(bool value) { _hasType = value; }
  std::string Distance::type() const { return _type; }
  void Distance::type(std::string value) { _type = value; }

  void Distance::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.c_str());
    }
  }
  void Distance::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = attr.as_string();
      _hasType = true;
    }
  }
}
