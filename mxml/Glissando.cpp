#include "Glissando.h"
#include <cstring>

namespace mxml
{
  Glissando::Glissando() {}
  bool Glissando::hasType() const { return _hasType; }
  void Glissando::hasType(bool value) { _hasType = value; }
  StartStopEnum Glissando::type() const { return _type; }
  void Glissando::type(StartStopEnum value) { _type = value; }
  bool Glissando::hasNumber() const { return _hasNumber; }
  void Glissando::hasNumber(bool value) { _hasNumber = value; }
  int Glissando::number() const { return _number; }
  void Glissando::number(int value) { _number = value; }

  void Glissando::ostreamAttrs(pugi::xml_node& self) const
  {
    LineType::ostreamAttrs(self);
    DashedFormatting::ostreamAttrs(self);
    PrintStyle::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
  }
  void Glissando::istreamAttrs(const pugi::xml_node& self)
  {
    LineType::istreamAttrs(self);
    DashedFormatting::istreamAttrs(self);
    PrintStyle::istreamAttrs(self);
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
