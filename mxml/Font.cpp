#include "Font.h"
#include <cstring>

namespace mxml
{
  Font::Font() {}
  bool Font::hasFontFamily() const { return _hasFontFamily; }
  void Font::hasFontFamily(bool value) { _hasFontFamily = value; }
  std::string Font::fontFamily() const { return _fontFamily; }
  void Font::fontFamily(std::string value) { _fontFamily = value; }
  bool Font::hasFontStyle() const { return _hasFontStyle; }
  void Font::hasFontStyle(bool value) { _hasFontStyle = value; }
  FontStyleEnum Font::fontStyle() const { return _fontStyle; }
  void Font::fontStyle(FontStyleEnum value) { _fontStyle = value; }
  bool Font::hasFontSize() const { return _hasFontSize; }
  void Font::hasFontSize(bool value) { _hasFontSize = value; }
  FontSizeEnum Font::fontSize() const { return _fontSize; }
  void Font::fontSize(FontSizeEnum value) { _fontSize = value; }
  bool Font::hasFontWeight() const { return _hasFontWeight; }
  void Font::hasFontWeight(bool value) { _hasFontWeight = value; }
  FontWeightEnum Font::fontWeight() const { return _fontWeight; }
  void Font::fontWeight(FontWeightEnum value) { _fontWeight = value; }

  void Font::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasFontFamily) {
      self.append_attribute("font-family").set_value(_fontFamily.c_str());
    }
    if(_hasFontStyle) {
      self.append_attribute("font-style").set_value(_fontStyle.operator const char *());
    }
    if(_hasFontSize) {
      self.append_attribute("font-size").set_value(_fontSize.operator const char *());
    }
    if(_hasFontWeight) {
      self.append_attribute("font-weight").set_value(_fontWeight.operator const char *());
    }
  }
  void Font::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("font-family")) {
      _fontFamily = attr.as_string();
      _hasFontFamily = true;
    }
    if(auto attr = self.attribute("font-style")) {
      _fontStyle = FontStyleEnum(attr.as_string());
      _hasFontStyle = true;
    }
    if(auto attr = self.attribute("font-size")) {
      _fontSize = FontSizeEnum(attr.as_string());
      _hasFontSize = true;
    }
    if(auto attr = self.attribute("font-weight")) {
      _fontWeight = FontWeightEnum(attr.as_string());
      _hasFontWeight = true;
    }
  }
}
