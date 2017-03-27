#include "RootStep.h"
#include <cstring>

namespace mxml
{
  RootStep::RootStep() {}
  bool RootStep::hasText() const { return _hasText; }
  void RootStep::hasText(bool value) { _hasText = value; }
  std::string RootStep::text() const { return _text; }
  void RootStep::text(std::string value) { _text = value; }

  void RootStep::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    if(_hasText) {
      self.append_attribute("text").set_value(_text.c_str());
    }
  }
  void RootStep::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    if(auto attr = self.attribute("text")) {
      _text = attr.as_string();
      _hasText = true;
    }
  }
}
