#include "Accidental.h"
#include <cstring>

namespace mxml
{
  Accidental::Accidental() {}
  bool Accidental::hasCautionary() const { return _hasCautionary; }
  void Accidental::hasCautionary(bool value) { _hasCautionary = value; }
  YesNoEnum Accidental::cautionary() const { return _cautionary; }
  void Accidental::cautionary(YesNoEnum value) { _cautionary = value; }
  bool Accidental::hasEditorial() const { return _hasEditorial; }
  void Accidental::hasEditorial(bool value) { _hasEditorial = value; }
  YesNoEnum Accidental::editorial() const { return _editorial; }
  void Accidental::editorial(YesNoEnum value) { _editorial = value; }

  void Accidental::ostreamAttrs(pugi::xml_node& self) const
  {
    LevelDisplay::ostreamAttrs(self);
    PrintStyle::ostreamAttrs(self);
    if(_hasCautionary) {
      self.append_attribute("cautionary").set_value(_cautionary.operator const char *());
    }
    if(_hasEditorial) {
      self.append_attribute("editorial").set_value(_editorial.operator const char *());
    }
  }
  void Accidental::istreamAttrs(const pugi::xml_node& self)
  {
    LevelDisplay::istreamAttrs(self);
    PrintStyle::istreamAttrs(self);
    if(auto attr = self.attribute("cautionary")) {
      _cautionary = YesNoEnum(attr.as_string());
      _hasCautionary = true;
    }
    if(auto attr = self.attribute("editorial")) {
      _editorial = YesNoEnum(attr.as_string());
      _hasEditorial = true;
    }
  }
}
