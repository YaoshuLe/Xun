#include "Level.h"
#include <cstring>

namespace mxml
{
  Level::Level() {}
  bool Level::hasReference() const { return _hasReference; }
  void Level::hasReference(bool value) { _hasReference = value; }
  YesNoEnum Level::reference() const { return _reference; }
  void Level::reference(YesNoEnum value) { _reference = value; }

  void Level::ostreamAttrs(pugi::xml_node& self) const
  {
    LevelDisplay::ostreamAttrs(self);
    if(_hasReference) {
      self.append_attribute("reference").set_value(_reference.operator const char *());
    }
  }
  void Level::istreamAttrs(const pugi::xml_node& self)
  {
    LevelDisplay::istreamAttrs(self);
    if(auto attr = self.attribute("reference")) {
      _reference = YesNoEnum(attr.as_string());
      _hasReference = true;
    }
  }
}
