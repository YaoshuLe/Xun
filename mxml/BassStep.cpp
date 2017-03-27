#include "BassStep.h"
#include <cstring>

namespace mxml
{
  BassStep::BassStep() {}
  bool BassStep::hasText() const { return _hasText; }
  void BassStep::hasText(bool value) { _hasText = value; }
  std::string BassStep::text() const { return _text; }
  void BassStep::text(std::string value) { _text = value; }

  void BassStep::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    if(_hasText) {
      self.append_attribute("text").set_value(_text.c_str());
    }
  }
  void BassStep::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    if(auto attr = self.attribute("text")) {
      _text = attr.as_string();
      _hasText = true;
    }
  }
}
