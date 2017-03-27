#include "Feature.h"
#include <cstring>

namespace mxml
{
  Feature::Feature() {}
  bool Feature::hasType() const { return _hasType; }
  void Feature::hasType(bool value) { _hasType = value; }
  std::string Feature::type() const { return _type; }
  void Feature::type(std::string value) { _type = value; }

  void Feature::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.c_str());
    }
  }
  void Feature::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = attr.as_string();
      _hasType = true;
    }
  }
}
