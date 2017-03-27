#include "Dashes.h"
#include <cstring>

namespace mxml
{
  Dashes::Dashes() {}
  bool Dashes::hasType() const { return _hasType; }
  void Dashes::hasType(bool value) { _hasType = value; }
  StartStopContinueEnum Dashes::type() const { return _type; }
  void Dashes::type(StartStopContinueEnum value) { _type = value; }
  bool Dashes::hasNumber() const { return _hasNumber; }
  void Dashes::hasNumber(bool value) { _hasNumber = value; }
  int Dashes::number() const { return _number; }
  void Dashes::number(int value) { _number = value; }

  void Dashes::ostreamAttrs(pugi::xml_node& self) const
  {
    DashedFormatting::ostreamAttrs(self);
    Position::ostreamAttrs(self);
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
  void Dashes::istreamAttrs(const pugi::xml_node& self)
  {
    DashedFormatting::istreamAttrs(self);
    Position::istreamAttrs(self);
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
