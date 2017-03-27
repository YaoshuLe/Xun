#include "TextFormatting.h"
#include <sstream>

namespace mxml
{
  TextFormatting::TextFormatting() {}
  bool TextFormatting::hasLang() const { return _hasLang; }
  void TextFormatting::hasLang(bool value) { _hasLang = value; }
  std::string TextFormatting::lang() const { return _lang; }
  void TextFormatting::lang(std::string value) { _lang = value; }
  bool TextFormatting::hasSpace() const { return _hasSpace; }
  void TextFormatting::hasSpace(bool value) { _hasSpace = value; }
  std::string TextFormatting::space() const { return _space; }
  void TextFormatting::space(std::string value) { _space = value; }
  void TextFormatting::ostreamAttrs(pugi::xml_node& self) const
  {
    Justify::ostreamAttrs(self);
    PrintStyleAlign::ostreamAttrs(self);
    TextDecoration::ostreamAttrs(self);
    TextRotation::ostreamAttrs(self);
    LetterSpacing::ostreamAttrs(self);
    LineHeight::ostreamAttrs(self);
    TextDirection::ostreamAttrs(self);
    Enclosure::ostreamAttrs(self);
    if(_hasLang) {
      self.append_attribute("xml:lang").set_value(_lang.c_str());
    }
    if(_hasSpace) {
      self.append_attribute("xml:space").set_value(_space.c_str());
    }
  }
  void TextFormatting::istreamAttrs(const pugi::xml_node& self)
  {
    Justify::istreamAttrs(self);
    PrintStyleAlign::istreamAttrs(self);
    TextDecoration::istreamAttrs(self);
    TextRotation::istreamAttrs(self);
    LetterSpacing::istreamAttrs(self);
    LineHeight::istreamAttrs(self);
    TextDirection::istreamAttrs(self);
    Enclosure::istreamAttrs(self);
    if(auto attr = self.attribute("xml:lang")) {
      _lang = attr.as_string();
      _hasLang = true;
    }
    if(auto attr = self.attribute("xml:space")) {
      _space = attr.as_string();
      _hasSpace = true;
    }
  }
}
