#include "NonArpeggiate.h"
#include <cstring>

namespace mxml
{
  NonArpeggiate::NonArpeggiate() {}
  bool NonArpeggiate::hasType() const { return _hasType; }
  void NonArpeggiate::hasType(bool value) { _hasType = value; }
  TopBottomEnum NonArpeggiate::type() const { return _type; }
  void NonArpeggiate::type(TopBottomEnum value) { _type = value; }
  bool NonArpeggiate::hasNumber() const { return _hasNumber; }
  void NonArpeggiate::hasNumber(bool value) { _hasNumber = value; }
  int NonArpeggiate::number() const { return _number; }
  void NonArpeggiate::number(int value) { _number = value; }

  void NonArpeggiate::ostreamAttrs(pugi::xml_node& self) const
  {
    Position::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
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
  void NonArpeggiate::istreamAttrs(const pugi::xml_node& self)
  {
    Position::istreamAttrs(self);
    Placement::istreamAttrs(self);
    Color::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = TopBottomEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
  }
}
