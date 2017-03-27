#include "Fingering.h"
#include <cstring>

namespace mxml
{
  Fingering::Fingering() {}
  bool Fingering::hasSubstitution() const { return _hasSubstitution; }
  void Fingering::hasSubstitution(bool value) { _hasSubstitution = value; }
  YesNoEnum Fingering::substitution() const { return _substitution; }
  void Fingering::substitution(YesNoEnum value) { _substitution = value; }
  bool Fingering::hasAlternate() const { return _hasAlternate; }
  void Fingering::hasAlternate(bool value) { _hasAlternate = value; }
  YesNoEnum Fingering::alternate() const { return _alternate; }
  void Fingering::alternate(YesNoEnum value) { _alternate = value; }

  void Fingering::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
    if(_hasSubstitution) {
      self.append_attribute("substitution").set_value(_substitution.operator const char *());
    }
    if(_hasAlternate) {
      self.append_attribute("alternate").set_value(_alternate.operator const char *());
    }
  }
  void Fingering::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
    if(auto attr = self.attribute("substitution")) {
      _substitution = YesNoEnum(attr.as_string());
      _hasSubstitution = true;
    }
    if(auto attr = self.attribute("alternate")) {
      _alternate = YesNoEnum(attr.as_string());
      _hasAlternate = true;
    }
  }
}
