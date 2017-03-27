#include "TextElementData.h"
#include <sstream>

namespace mxml
{
  TextElementData::TextElementData(){}
  bool TextElementData::hasLang() const { return _hasLang; }
  void TextElementData::hasLang(bool value) { _hasLang = value; }
  std::string TextElementData::lang() const { return _lang; }
  void TextElementData::lang(std::string value) { _lang = value; }
  void TextElementData::ostreamAttrs(pugi::xml_node& self) const
  {
    Font::ostreamAttrs(self);
    Color::ostreamAttrs(self);
    TextDecoration::ostreamAttrs(self);
    TextRotation::ostreamAttrs(self);
    LetterSpacing::ostreamAttrs(self);
    TextDirection::ostreamAttrs(self);
    if(_hasLang) {
      self.append_attribute("xml:lang").set_value(_lang.c_str());
    }
  }
  void TextElementData::istreamAttrs(const pugi::xml_node& self)
  {
    Font::istreamAttrs(self);
    Color::istreamAttrs(self);
    TextDecoration::istreamAttrs(self);
    TextRotation::istreamAttrs(self);
    LetterSpacing::istreamAttrs(self);
    TextDirection::istreamAttrs(self);
    if(auto attr = self.attribute("xml:lang")) {
      _lang = attr.as_string();
      _hasLang = true;
    }
  }
}
