#include "DegreeValue.h"
#include <cstring>

namespace mxml
{
  DegreeValue::DegreeValue() {}
  bool DegreeValue::hasSymbol() const { return _hasSymbol; }
  void DegreeValue::hasSymbol(bool value) { _hasSymbol = value; }
  DegreeSymbolValueEnum DegreeValue::symbol() const { return _symbol; }
  void DegreeValue::symbol(DegreeSymbolValueEnum value) { _symbol = value; }
  bool DegreeValue::hasText() const { return _hasText; }
  void DegreeValue::hasText(bool value) { _hasText = value; }
  std::string DegreeValue::text() const { return _text; }
  void DegreeValue::text(std::string value) { _text = value; }

  void DegreeValue::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    if(_hasSymbol) {
      self.append_attribute("symbol").set_value(_symbol.operator const char *());
    }
    if(_hasText) {
      self.append_attribute("text").set_value(_text.c_str());
    }
  }
  void DegreeValue::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    if(auto attr = self.attribute("symbol")) {
      _symbol = DegreeSymbolValueEnum(attr.as_string());
      _hasSymbol = true;
    }
    if(auto attr = self.attribute("text")) {
      _text = attr.as_string();
      _hasText = true;
    }
  }
}
