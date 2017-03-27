#include "OtherAppearance.h"
#include <cstring>

namespace mxml
{
  OtherAppearance::OtherAppearance() {}
  bool OtherAppearance::hasType() const { return _hasType; }
  void OtherAppearance::hasType(bool value) { _hasType = value; }
  std::string OtherAppearance::type() const { return _type; }
  void OtherAppearance::type(std::string value) { _type = value; }

  void OtherAppearance::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.c_str());
    }
  }
  void OtherAppearance::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = attr.as_string();
      _hasType = true;
    }
  }
}
