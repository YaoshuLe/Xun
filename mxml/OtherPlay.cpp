#include "OtherPlay.h"
#include <cstring>

namespace mxml
{
  OtherPlay::OtherPlay() {}
  bool OtherPlay::hasType() const { return _hasType; }
  void OtherPlay::hasType(bool value) { _hasType = value; }
  std::string OtherPlay::type() const { return _type; }
  void OtherPlay::type(std::string value) { _type = value; }

  void OtherPlay::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.c_str());
    }
  }
  void OtherPlay::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = attr.as_string();
      _hasType = true;
    }
  }
}
