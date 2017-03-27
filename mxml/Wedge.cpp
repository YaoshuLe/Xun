#include "Wedge.h"
#include <cstring>

namespace mxml
{
  Wedge::Wedge() {}
  bool Wedge::hasType() const { return _hasType; }
  void Wedge::hasType(bool value) { _hasType = value; }
  WedgeTypeEnum Wedge::type() const { return _type; }
  void Wedge::type(WedgeTypeEnum value) { _type = value; }
  bool Wedge::hasNumber() const { return _hasNumber; }
  void Wedge::hasNumber(bool value) { _hasNumber = value; }
  int Wedge::number() const { return _number; }
  void Wedge::number(int value) { _number = value; }
  bool Wedge::hasSpread() const { return _hasSpread; }
  void Wedge::hasSpread(bool value) { _hasSpread = value; }
  float Wedge::spread() const { return _spread; }
  void Wedge::spread(float value) { _spread = value; }
  bool Wedge::hasNiente() const { return _hasNiente; }
  void Wedge::hasNiente(bool value) { _hasNiente = value; }
  YesNoEnum Wedge::niente() const { return _niente; }
  void Wedge::niente(YesNoEnum value) { _niente = value; }

  void Wedge::ostreamAttrs(pugi::xml_node& self) const
  {
    LineType::ostreamAttrs(self);
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
    if(_hasSpread) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _spread);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("spread").set_value(str);
    }
    if(_hasNiente) {
      self.append_attribute("niente").set_value(_niente.operator const char *());
    }
  }
  void Wedge::istreamAttrs(const pugi::xml_node& self)
  {
    LineType::istreamAttrs(self);
    DashedFormatting::istreamAttrs(self);
    Position::istreamAttrs(self);
    Color::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = WedgeTypeEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("spread")) {
      _spread = attr.as_float();
      _hasSpread = true;
    }
    if(auto attr = self.attribute("niente")) {
      _niente = YesNoEnum(attr.as_string());
      _hasNiente = true;
    }
  }
}
