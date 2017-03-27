#include "Enclosure.h"
#include <cstring>

namespace mxml
{
  Enclosure::Enclosure() {}
  bool Enclosure::hasEnclosure() const { return _hasEnclosure; }
  void Enclosure::hasEnclosure(bool value) { _hasEnclosure = value; }
  EnclosureShapeEnum Enclosure::enclosure() const { return _enclosure; }
  void Enclosure::enclosure(EnclosureShapeEnum value) { _enclosure = value; }

  void Enclosure::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasEnclosure) {
      self.append_attribute("enclosure").set_value(_enclosure.operator const char *());
    }
  }
  void Enclosure::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("enclosure")) {
      _enclosure = EnclosureShapeEnum(attr.as_string());
      _hasEnclosure = true;
    }
  }
}
