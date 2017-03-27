#include "Tied.h"
#include <cstring>

namespace mxml
{
  Tied::Tied() {}
  bool Tied::hasType() const { return _hasType; }
  void Tied::hasType(bool value) { _hasType = value; }
  StartStopContinueEnum Tied::type() const { return _type; }
  void Tied::type(StartStopContinueEnum value) { _type = value; }
  bool Tied::hasNumber() const { return _hasNumber; }
  void Tied::hasNumber(bool value) { _hasNumber = value; }
  int Tied::number() const { return _number; }
  void Tied::number(int value) { _number = value; }

  void Tied::ostreamAttrs(pugi::xml_node& self) const
  {
    LineType::ostreamAttrs(self);
    DashedFormatting::ostreamAttrs(self);
    Position::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
    Orientation::ostreamAttrs(self);
    Bezier::ostreamAttrs(self);
    Color::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
  }
  void Tied::istreamAttrs(const pugi::xml_node& self)
  {
    LineType::istreamAttrs(self);
    DashedFormatting::istreamAttrs(self);
    Position::istreamAttrs(self);
    Placement::istreamAttrs(self);
    Orientation::istreamAttrs(self);
    Bezier::istreamAttrs(self);
    Color::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = StartStopContinueEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
  }
}
