#include "LineWidth.h"
#include <cstring>

namespace mxml
{
  LineWidth::LineWidth() {}
  bool LineWidth::hasType() const { return _hasType; }
  void LineWidth::hasType(bool value) { _hasType = value; }
  std::string LineWidth::type() const { return _type; }
  void LineWidth::type(std::string value) { _type = value; }

  void LineWidth::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.c_str());
    }
  }
  void LineWidth::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = attr.as_string();
      _hasType = true;
    }
  }
}
