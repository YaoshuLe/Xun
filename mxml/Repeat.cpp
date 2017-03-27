#include "Repeat.h"
#include <cstring>

namespace mxml
{
  Repeat::Repeat() {}
  bool Repeat::hasDirection() const { return _hasDirection; }
  void Repeat::hasDirection(bool value) { _hasDirection = value; }
  BackwardForwardEnum Repeat::direction() const { return _direction; }
  void Repeat::direction(BackwardForwardEnum value) { _direction = value; }
  bool Repeat::hasTimes() const { return _hasTimes; }
  void Repeat::hasTimes(bool value) { _hasTimes = value; }
  int Repeat::times() const { return _times; }
  void Repeat::times(int value) { _times = value; }
  bool Repeat::hasWinged() const { return _hasWinged; }
  void Repeat::hasWinged(bool value) { _hasWinged = value; }
  WingedEnum Repeat::winged() const { return _winged; }
  void Repeat::winged(WingedEnum value) { _winged = value; }

  void Repeat::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasDirection) {
      self.append_attribute("direction").set_value(_direction.operator const char *());
    }
    if(_hasTimes) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _times);
      self.append_attribute("times").set_value(str);
    }
    if(_hasWinged) {
      self.append_attribute("winged").set_value(_winged.operator const char *());
    }
  }
  void Repeat::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("direction")) {
      _direction = BackwardForwardEnum(attr.as_string());
      _hasDirection = true;
    }
    if(auto attr = self.attribute("times")) {
      _times = attr.as_int();
      _hasTimes = true;
    }
    if(auto attr = self.attribute("winged")) {
      _winged = WingedEnum(attr.as_string());
      _hasWinged = true;
    }
  }
}
