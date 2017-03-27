#include "Beam.h"
#include <cstring>

namespace mxml
{
  Beam::Beam() {}
  bool Beam::hasNumber() const { return _hasNumber; }
  void Beam::hasNumber(bool value) { _hasNumber = value; }
  int Beam::number() const { return _number; }
  void Beam::number(int value) { _number = value; }
  bool Beam::hasRepeater() const { return _hasRepeater; }
  void Beam::hasRepeater(bool value) { _hasRepeater = value; }
  YesNoEnum Beam::repeater() const { return _repeater; }
  void Beam::repeater(YesNoEnum value) { _repeater = value; }
  bool Beam::hasFan() const { return _hasFan; }
  void Beam::hasFan(bool value) { _hasFan = value; }
  FanEnum Beam::fan() const { return _fan; }
  void Beam::fan(FanEnum value) { _fan = value; }

  void Beam::ostreamAttrs(pugi::xml_node& self) const
  {
    Color::ostreamAttrs(self);
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
    if(_hasRepeater) {
      self.append_attribute("repeater").set_value(_repeater.operator const char *());
    }
    if(_hasFan) {
      self.append_attribute("fan").set_value(_fan.operator const char *());
    }
  }
  void Beam::istreamAttrs(const pugi::xml_node& self)
  {
    Color::istreamAttrs(self);
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("repeater")) {
      _repeater = YesNoEnum(attr.as_string());
      _hasRepeater = true;
    }
    if(auto attr = self.attribute("fan")) {
      _fan = FanEnum(attr.as_string());
      _hasFan = true;
    }
  }
}
