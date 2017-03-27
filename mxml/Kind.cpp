#include "Kind.h"
#include <cstring>

namespace mxml
{
  Kind::Kind() {}
  bool Kind::hasUseSymbols() const { return _hasUseSymbols; }
  void Kind::hasUseSymbols(bool value) { _hasUseSymbols = value; }
  YesNoEnum Kind::useSymbols() const { return _useSymbols; }
  void Kind::useSymbols(YesNoEnum value) { _useSymbols = value; }
  bool Kind::hasText() const { return _hasText; }
  void Kind::hasText(bool value) { _hasText = value; }
  std::string Kind::text() const { return _text; }
  void Kind::text(std::string value) { _text = value; }
  bool Kind::hasStackDegrees() const { return _hasStackDegrees; }
  void Kind::hasStackDegrees(bool value) { _hasStackDegrees = value; }
  YesNoEnum Kind::stackDegrees() const { return _stackDegrees; }
  void Kind::stackDegrees(YesNoEnum value) { _stackDegrees = value; }
  bool Kind::hasParenthesesDegrees() const { return _hasParenthesesDegrees; }
  void Kind::hasParenthesesDegrees(bool value) { _hasParenthesesDegrees = value; }
  YesNoEnum Kind::parenthesesDegrees() const { return _parenthesesDegrees; }
  void Kind::parenthesesDegrees(YesNoEnum value) { _parenthesesDegrees = value; }
  bool Kind::hasBracketDegrees() const { return _hasBracketDegrees; }
  void Kind::hasBracketDegrees(bool value) { _hasBracketDegrees = value; }
  YesNoEnum Kind::bracketDegrees() const { return _bracketDegrees; }
  void Kind::bracketDegrees(YesNoEnum value) { _bracketDegrees = value; }

  void Kind::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Halign::ostreamAttrs(self);
    Valign::ostreamAttrs(self);
    if(_hasUseSymbols) {
      self.append_attribute("use-symbols").set_value(_useSymbols.operator const char *());
    }
    if(_hasText) {
      self.append_attribute("text").set_value(_text.c_str());
    }
    if(_hasStackDegrees) {
      self.append_attribute("stack-degrees").set_value(_stackDegrees.operator const char *());
    }
    if(_hasParenthesesDegrees) {
      self.append_attribute("parentheses-degrees").set_value(_parenthesesDegrees.operator const char *());
    }
    if(_hasBracketDegrees) {
      self.append_attribute("bracket-degrees").set_value(_bracketDegrees.operator const char *());
    }
  }
  void Kind::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Halign::istreamAttrs(self);
    Valign::istreamAttrs(self);
    if(auto attr = self.attribute("use-symbols")) {
      _useSymbols = YesNoEnum(attr.as_string());
      _hasUseSymbols = true;
    }
    if(auto attr = self.attribute("text")) {
      _text = attr.as_string();
      _hasText = true;
    }
    if(auto attr = self.attribute("stack-degrees")) {
      _stackDegrees = YesNoEnum(attr.as_string());
      _hasStackDegrees = true;
    }
    if(auto attr = self.attribute("parentheses-degrees")) {
      _parenthesesDegrees = YesNoEnum(attr.as_string());
      _hasParenthesesDegrees = true;
    }
    if(auto attr = self.attribute("bracket-degrees")) {
      _bracketDegrees = YesNoEnum(attr.as_string());
      _hasBracketDegrees = true;
    }
  }
}
