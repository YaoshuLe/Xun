#include "TextDecoration.h"
#include <cstring>

namespace mxml
{
  TextDecoration::TextDecoration() {}
  bool TextDecoration::hasUnderline() const { return _hasUnderline; }
  void TextDecoration::hasUnderline(bool value) { _hasUnderline = value; }
  int TextDecoration::underline() const { return _underline; }
  void TextDecoration::underline(int value) { _underline = value; }
  bool TextDecoration::hasOverline() const { return _hasOverline; }
  void TextDecoration::hasOverline(bool value) { _hasOverline = value; }
  int TextDecoration::overline() const { return _overline; }
  void TextDecoration::overline(int value) { _overline = value; }
  bool TextDecoration::hasLineThrough() const { return _hasLineThrough; }
  void TextDecoration::hasLineThrough(bool value) { _hasLineThrough = value; }
  int TextDecoration::lineThrough() const { return _lineThrough; }
  void TextDecoration::lineThrough(int value) { _lineThrough = value; }

  void TextDecoration::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasUnderline) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _underline);
      self.append_attribute("underline").set_value(str);
    }
    if(_hasOverline) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _overline);
      self.append_attribute("overline").set_value(str);
    }
    if(_hasLineThrough) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _lineThrough);
      self.append_attribute("line-through").set_value(str);
    }
  }
  void TextDecoration::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("underline")) {
      _underline = attr.as_int();
      _hasUnderline = true;
    }
    if(auto attr = self.attribute("overline")) {
      _overline = attr.as_int();
      _hasOverline = true;
    }
    if(auto attr = self.attribute("line-through")) {
      _lineThrough = attr.as_int();
      _hasLineThrough = true;
    }
  }
}
