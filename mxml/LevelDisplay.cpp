#include "LevelDisplay.h"
#include <cstring>

namespace mxml
{
  LevelDisplay::LevelDisplay() {}
  bool LevelDisplay::hasParentheses() const { return _hasParentheses; }
  void LevelDisplay::hasParentheses(bool value) { _hasParentheses = value; }
  YesNoEnum LevelDisplay::parentheses() const { return _parentheses; }
  void LevelDisplay::parentheses(YesNoEnum value) { _parentheses = value; }
  bool LevelDisplay::hasBracket() const { return _hasBracket; }
  void LevelDisplay::hasBracket(bool value) { _hasBracket = value; }
  YesNoEnum LevelDisplay::bracket() const { return _bracket; }
  void LevelDisplay::bracket(YesNoEnum value) { _bracket = value; }
  bool LevelDisplay::hasSize() const { return _hasSize; }
  void LevelDisplay::hasSize(bool value) { _hasSize = value; }
  SymbolSizeEnum LevelDisplay::size() const { return _size; }
  void LevelDisplay::size(SymbolSizeEnum value) { _size = value; }

  void LevelDisplay::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasParentheses) {
      self.append_attribute("parentheses").set_value(_parentheses.operator const char *());
    }
    if(_hasBracket) {
      self.append_attribute("bracket").set_value(_bracket.operator const char *());
    }
    if(_hasSize) {
      self.append_attribute("size").set_value(_size.operator const char *());
    }
  }
  void LevelDisplay::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("parentheses")) {
      _parentheses = YesNoEnum(attr.as_string());
      _hasParentheses = true;
    }
    if(auto attr = self.attribute("bracket")) {
      _bracket = YesNoEnum(attr.as_string());
      _hasBracket = true;
    }
    if(auto attr = self.attribute("size")) {
      _size = SymbolSizeEnum(attr.as_string());
      _hasSize = true;
    }
  }
}
