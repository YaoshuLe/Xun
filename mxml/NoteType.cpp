#include "NoteType.h"
#include <cstring>

namespace mxml
{
  NoteType::NoteType() {}
  bool NoteType::hasSize() const { return _hasSize; }
  void NoteType::hasSize(bool value) { _hasSize = value; }
  SymbolSizeEnum NoteType::size() const { return _size; }
  void NoteType::size(SymbolSizeEnum value) { _size = value; }

  void NoteType::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasSize) {
      self.append_attribute("size").set_value(_size.operator const char *());
    }
  }
  void NoteType::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("size")) {
      _size = SymbolSizeEnum(attr.as_string());
      _hasSize = true;
    }
  }
}
