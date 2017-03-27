#include "PartAttributes.h"
#include <cstring>

namespace mxml
{
  PartAttributes::PartAttributes() {}
  bool PartAttributes::hasId() const { return _hasId; }
  void PartAttributes::hasId(bool value) { _hasId = value; }
  std::string PartAttributes::id() const { return _id; }
  void PartAttributes::id(std::string value) { _id = value; }

  void PartAttributes::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasId) {
      self.append_attribute("id").set_value(_id.c_str());
    }
  }
  void PartAttributes::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("id")) {
      _id = attr.as_string();
      _hasId = true;
    }
  }
}
