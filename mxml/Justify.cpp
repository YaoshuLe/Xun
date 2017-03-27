#include "Justify.h"
#include <cstring>

namespace mxml
{
  Justify::Justify() {}
  bool Justify::hasJustify() const { return _hasJustify; }
  void Justify::hasJustify(bool value) { _hasJustify = value; }
  LeftCenterRightEnum Justify::justify() const { return _justify; }
  void Justify::justify(LeftCenterRightEnum value) { _justify = value; }

  void Justify::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasJustify) {
      self.append_attribute("justify").set_value(_justify.operator const char *());
    }
  }
  void Justify::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("justify")) {
      _justify = LeftCenterRightEnum(attr.as_string());
      _hasJustify = true;
    }
  }
}
