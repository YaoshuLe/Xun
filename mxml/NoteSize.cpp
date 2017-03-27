#include "NoteSize.h"
#include <cstring>

namespace mxml
{
  NoteSize::NoteSize() {}
  bool NoteSize::hasType() const { return _hasType; }
  void NoteSize::hasType(bool value) { _hasType = value; }
  NoteSizeTypeEnum NoteSize::type() const { return _type; }
  void NoteSize::type(NoteSizeTypeEnum value) { _type = value; }

  void NoteSize::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
  }
  void NoteSize::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = NoteSizeTypeEnum(attr.as_string());
      _hasType = true;
    }
  }
}
