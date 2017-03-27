#include "Mordent.h"
#include <sstream>

namespace mxml
{
  Mordent::Mordent() {}
  bool Mordent::hasLength() const { return _hasLength; }
  void Mordent::hasLength(bool value) { _hasLength = value; }
  YesNoEnum Mordent::length() const { return _length; }
  void Mordent::length(YesNoEnum value) { _length = value; }
  bool Mordent::hasApproach() const { return _hasApproach; }
  void Mordent::hasApproach(bool value) { _hasApproach = value; }
  AboveBelowEnum Mordent::approach() const { return _approach; }
  void Mordent::approach(AboveBelowEnum value) { _approach = value; }
  bool Mordent::hasDeparture() const { return _hasDeparture; }
  void Mordent::hasDeparture(bool value) { _hasDeparture = value; }
  AboveBelowEnum Mordent::departure() const { return _departure; }
  void Mordent::departure(AboveBelowEnum value) { _departure = value; }

  void Mordent::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
    TrillSound::ostreamAttrs(self);  
    if(_hasLength) {
      self.append_attribute("long").set_value(_length.operator const char *());
    }
    if(_hasApproach) {
      self.append_attribute("approach").set_value(_approach.operator const char *());
    }
    if(_hasDeparture) {
      self.append_attribute("departure").set_value(_departure.operator const char *());
    }
  }
  void Mordent::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
    TrillSound::istreamAttrs(self);  
    if(auto attr = self.attribute("long")) {
      _length = YesNoEnum(attr.as_string());
      _hasLength = true;
    }
    if(auto attr = self.attribute("approach")) {
      _approach = AboveBelowEnum(attr.as_string());
      _hasApproach = true;
    }
    if(auto attr = self.attribute("departure")) {
      _departure = AboveBelowEnum(attr.as_string());
      _hasDeparture = true;
    }
  }
}
