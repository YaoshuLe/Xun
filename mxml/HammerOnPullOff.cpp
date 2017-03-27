#include "HammerOnPullOff.h"
#include <cstring>

namespace mxml
{
  HammerOnPullOff::HammerOnPullOff() {}
  bool HammerOnPullOff::hasType() const { return _hasType; }
  void HammerOnPullOff::hasType(bool value) { _hasType = value; }
  StartStopEnum HammerOnPullOff::type() const { return _type; }
  void HammerOnPullOff::type(StartStopEnum value) { _type = value; }
  bool HammerOnPullOff::hasNumber() const { return _hasNumber; }
  void HammerOnPullOff::hasNumber(bool value) { _hasNumber = value; }
  int HammerOnPullOff::number() const { return _number; }
  void HammerOnPullOff::number(int value) { _number = value; }

  void HammerOnPullOff::ostreamAttrs(pugi::xml_node& self) const
  {
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
  void HammerOnPullOff::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = StartStopEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
  }
}
