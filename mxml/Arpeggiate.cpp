#include "Arpeggiate.h"
#include <cstring>

namespace mxml
{
  Arpeggiate::Arpeggiate() {}
  bool Arpeggiate::hasNumber() const { return _hasNumber; }
  void Arpeggiate::hasNumber(bool value) { _hasNumber = value; }
  int Arpeggiate::number() const { return _number; }
  void Arpeggiate::number(int value) { _number = value; }
  bool Arpeggiate::hasDirection() const { return _hasDirection; }
  void Arpeggiate::hasDirection(bool value) { _hasDirection = value; }
  UpDownEnum Arpeggiate::direction() const { return _direction; }
  void Arpeggiate::direction(UpDownEnum value) { _direction = value; }

  void Arpeggiate::ostreamAttrs(pugi::xml_node& self) const
  {
    Position::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
    Color::ostreamAttrs(self);
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
    if(_hasDirection) {
      self.append_attribute("direction").set_value(_direction.operator const char *());
    }
  }
  void Arpeggiate::istreamAttrs(const pugi::xml_node& self)
  {
    Position::istreamAttrs(self);
    Placement::istreamAttrs(self);
    Color::istreamAttrs(self);
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("direction")) {
      _direction = UpDownEnum(attr.as_string());
      _hasDirection = true;
    }
  }
}
