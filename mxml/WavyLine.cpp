#include "WavyLine.h"
#include <cstring>

namespace mxml
{
  WavyLine::WavyLine() {}
  bool WavyLine::hasType() const { return _hasType; }
  void WavyLine::hasType(bool value) { _hasType = value; }
  StartStopContinueEnum WavyLine::type() const { return _type; }
  void WavyLine::type(StartStopContinueEnum value) { _type = value; }
  bool WavyLine::hasNumber() const { return _hasNumber; }
  void WavyLine::hasNumber(bool value) { _hasNumber = value; }
  int WavyLine::number() const { return _number; }
  void WavyLine::number(int value) { _number = value; }

  void WavyLine::ostreamAttrs(pugi::xml_node& self) const
  {
    Position::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
    Color::ostreamAttrs(self);
    TrillSound::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
  }
  void WavyLine::istreamAttrs(const pugi::xml_node& self)
  {
    Position::istreamAttrs(self);
    Placement::istreamAttrs(self);
    Color::istreamAttrs(self);
    TrillSound::istreamAttrs(self);
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
