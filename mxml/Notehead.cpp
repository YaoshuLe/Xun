#include "Notehead.h"
#include <cstring>

namespace mxml
{
  Notehead::Notehead() {}
  bool Notehead::hasFilled() const { return _hasFilled; }
  void Notehead::hasFilled(bool value) { _hasFilled = value; }
  YesNoEnum Notehead::filled() const { return _filled; }
  void Notehead::filled(YesNoEnum value) { _filled = value; }
  bool Notehead::hasParentheses() const { return _hasParentheses; }
  void Notehead::hasParentheses(bool value) { _hasParentheses = value; }
  YesNoEnum Notehead::parentheses() const { return _parentheses; }
  void Notehead::parentheses(YesNoEnum value) { _parentheses = value; }

  void Notehead::ostreamAttrs(pugi::xml_node& self) const
  {
    Font::ostreamAttrs(self);
    Color::ostreamAttrs(self);
    if(_hasFilled) {
      self.append_attribute("filled").set_value(_filled.operator const char *());
    }
    if(_hasParentheses) {
      self.append_attribute("parentheses").set_value(_parentheses.operator const char *());
    }
  }
  void Notehead::istreamAttrs(const pugi::xml_node& self)
  {
    Font::istreamAttrs(self);
    Color::istreamAttrs(self);
    if(auto attr = self.attribute("filled")) {
      _filled = YesNoEnum(attr.as_string());
      _hasFilled = true;
    }
    if(auto attr = self.attribute("parentheses")) {
      _parentheses = YesNoEnum(attr.as_string());
      _hasParentheses = true;
    }
  }
}
