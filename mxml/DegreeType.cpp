#include "DegreeType.h"
#include <cstring>

namespace mxml
{
  DegreeType::DegreeType() {}
  bool DegreeType::hasText() const { return _hasText; }
  void DegreeType::hasText(bool value) { _hasText = value; }
  std::string DegreeType::text() const { return _text; }
  void DegreeType::text(std::string value) { _text = value; }

  void DegreeType::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    if(_hasText) {
      self.append_attribute("text").set_value(_text.c_str());
    }
  }
  void DegreeType::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    if(auto attr = self.attribute("text")) {
      _text = attr.as_string();
      _hasText = true;
    }
  }
}
