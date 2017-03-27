#include "Pedal.h"
#include <cstring>

namespace mxml
{
  Pedal::Pedal() {}
  bool Pedal::hasType() const { return _hasType; }
  void Pedal::hasType(bool value) { _hasType = value; }
  StartStopChangeContinueEnum Pedal::type() const { return _type; }
  void Pedal::type(StartStopChangeContinueEnum value) { _type = value; }
  bool Pedal::hasLine() const { return _hasLine; }
  void Pedal::hasLine(bool value) { _hasLine = value; }
  YesNoEnum Pedal::line() const { return _line; }
  void Pedal::line(YesNoEnum value) { _line = value; }
  bool Pedal::hasSign() const { return _hasSign; }
  void Pedal::hasSign(bool value) { _hasSign = value; }
  YesNoEnum Pedal::sign() const { return _sign; }
  void Pedal::sign(YesNoEnum value) { _sign = value; }

  void Pedal::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyleAlign::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasLine) {
      self.append_attribute("line").set_value(_line.operator const char *());
    }
    if(_hasSign) {
      self.append_attribute("sign").set_value(_sign.operator const char *());
    }
  }
  void Pedal::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyleAlign::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = StartStopChangeContinueEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("line")) {
      _line = YesNoEnum(attr.as_string());
      _hasLine = true;
    }
    if(auto attr = self.attribute("sign")) {
      _sign = YesNoEnum(attr.as_string());
      _hasSign = true;
    }
  }
}
