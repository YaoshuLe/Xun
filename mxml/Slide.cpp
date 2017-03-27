#include "Slide.h"
#include <cstring>

namespace mxml
{
  Slide::Slide() {}
  bool Slide::hasType() const { return _hasType; }
  void Slide::hasType(bool value) { _hasType = value; }
  StartStopEnum Slide::type() const { return _type; }
  void Slide::type(StartStopEnum value) { _type = value; }
  bool Slide::hasNumber() const { return _hasNumber; }
  void Slide::hasNumber(bool value) { _hasNumber = value; }
  int Slide::number() const { return _number; }
  void Slide::number(int value) { _number = value; }

  void Slide::ostreamAttrs(pugi::xml_node& self) const
  {
    LineType::ostreamAttrs(self);
    DashedFormatting::ostreamAttrs(self);
    PrintStyle::ostreamAttrs(self);
    BendSound::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
  }
  void Slide::istreamAttrs(const pugi::xml_node& self)
  {
    LineType::istreamAttrs(self);
    DashedFormatting::istreamAttrs(self);
    PrintStyle::istreamAttrs(self);
    BendSound::istreamAttrs(self);
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
