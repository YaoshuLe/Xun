#include "HeelToe.h"
#include <cstring>

namespace mxml
{
  HeelToe::HeelToe() {}
  bool HeelToe::hasSubstitution() const { return _hasSubstitution; }
  void HeelToe::hasSubstitution(bool value) { _hasSubstitution = value; }
  YesNoEnum HeelToe::substitution() const { return _substitution; }
  void HeelToe::substitution(YesNoEnum value) { _substitution = value; }

  void HeelToe::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
    if(_hasSubstitution) {
      self.append_attribute("substitution").set_value(_substitution.operator const char *());
    }
  }
  void HeelToe::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
    if(auto attr = self.attribute("substitution")) {
      _substitution = YesNoEnum(attr.as_string());
      _hasSubstitution = true;
    }
  }
}
