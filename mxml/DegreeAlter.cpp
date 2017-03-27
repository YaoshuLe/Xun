#include "DegreeAlter.h"
#include <cstring>

namespace mxml
{
  DegreeAlter::DegreeAlter() {}
  bool DegreeAlter::hasPlusMinus() const { return _hasPlusMinus; }
  void DegreeAlter::hasPlusMinus(bool value) { _hasPlusMinus = value; }
  YesNoEnum DegreeAlter::plusMinus() const { return _plusMinus; }
  void DegreeAlter::plusMinus(YesNoEnum value) { _plusMinus = value; }

  void DegreeAlter::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    if(_hasPlusMinus) {
      self.append_attribute("plus-minus").set_value(_plusMinus.operator const char *());
    }
  }
  void DegreeAlter::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    if(auto attr = self.attribute("plus-minus")) {
      _plusMinus = YesNoEnum(attr.as_string());
      _hasPlusMinus = true;
    }
  }
}
