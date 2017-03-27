#include "Offset.h"
#include <cstring>

namespace mxml
{
  Offset::Offset() {}
  bool Offset::hasSound() const { return _hasSound; }
  void Offset::hasSound(bool value) { _hasSound = value; }
  YesNoEnum Offset::sound() const { return _sound; }
  void Offset::sound(YesNoEnum value) { _sound = value; }

  void Offset::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasSound) {
      self.append_attribute("sound").set_value(_sound.operator const char *());
    }
  }
  void Offset::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("sound")) {
      _sound = YesNoEnum(attr.as_string());
      _hasSound = true;
    }
  }
}
