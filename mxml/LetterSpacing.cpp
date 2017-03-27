#include "LetterSpacing.h"
#include <cstring>

namespace mxml
{
  LetterSpacing::LetterSpacing() {}
  bool LetterSpacing::hasLetterSpacing() const { return _hasLetterSpacing; }
  void LetterSpacing::hasLetterSpacing(bool value) { _hasLetterSpacing = value; }
  NumberOrNormalEnum LetterSpacing::letterSpacing() const { return _letterSpacing; }
  void LetterSpacing::letterSpacing(NumberOrNormalEnum value) { _letterSpacing = value; }

  void LetterSpacing::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasLetterSpacing) {
      self.append_attribute("letter-spacing").set_value(_letterSpacing.operator const char *());
    }
  }
  void LetterSpacing::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("letter-spacing")) {
      _letterSpacing = NumberOrNormalEnum(attr.as_string());
      _hasLetterSpacing = true;
    }
  }
}
