#include "HorizontalTurn.h"
#include <cstring>

namespace mxml
{
  HorizontalTurn::HorizontalTurn() {}
  bool HorizontalTurn::hasSlash() const { return _hasSlash; }
  void HorizontalTurn::hasSlash(bool value) { _hasSlash = value; }
  YesNoEnum HorizontalTurn::slash() const { return _slash; }
  void HorizontalTurn::slash(YesNoEnum value) { _slash = value; }

  void HorizontalTurn::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
    TrillSound::ostreamAttrs(self);
    if(_hasSlash) {
      self.append_attribute("slash").set_value(_slash.operator const char *());
    }
  }
  void HorizontalTurn::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
    TrillSound::istreamAttrs(self);
    if(auto attr = self.attribute("slash")) {
      _slash = YesNoEnum(attr.as_string());
      _hasSlash = true;
    }
  }
}
