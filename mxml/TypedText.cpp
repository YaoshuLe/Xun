#include "TypedText.h"
#include <cstring>

namespace mxml
{
  TypedText::TypedText() {}
  bool TypedText::hasType() const { return _hasType; }
  void TypedText::hasType(bool value) { _hasType = value; }
  std::string TypedText::type() const { return _type; }
  void TypedText::type(std::string value) { _type = value; }

  void TypedText::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.c_str());
    }
  }
  void TypedText::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = attr.as_string();
      _hasType = true;
    }
  }
}
