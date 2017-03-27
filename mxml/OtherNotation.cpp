#include "OtherNotation.h"
#include <cstring>

namespace mxml
{
  OtherNotation::OtherNotation() {}
  bool OtherNotation::hasType() const { return _hasType; }
  void OtherNotation::hasType(bool value) { _hasType = value; }
  StartStopSingleEnum OtherNotation::type() const { return _type; }
  void OtherNotation::type(StartStopSingleEnum value) { _type = value; }
  bool OtherNotation::hasNumber() const { return _hasNumber; }
  void OtherNotation::hasNumber(bool value) { _hasNumber = value; }
  int OtherNotation::number() const { return _number; }
  void OtherNotation::number(int value) { _number = value; }

  void OtherNotation::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintObject::ostreamAttrs(self);
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
  }
  void OtherNotation::istreamAttrs(const pugi::xml_node& self)
  {
    PrintObject::istreamAttrs(self);
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = StartStopSingleEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
  }
}
