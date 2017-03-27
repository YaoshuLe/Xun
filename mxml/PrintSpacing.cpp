#include "PrintSpacing.h"
#include <cstring>

namespace mxml
{
  PrintSpacing::PrintSpacing() {}
  bool PrintSpacing::hasPrintSpacing() const { return _hasPrintSpacing; }
  void PrintSpacing::hasPrintSpacing(bool value) { _hasPrintSpacing = value; }
  YesNoEnum PrintSpacing::printSpacing() const { return _printSpacing; }
  void PrintSpacing::printSpacing(YesNoEnum value) { _printSpacing = value; }

  void PrintSpacing::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasPrintSpacing) {
      self.append_attribute("print-spacing").set_value(_printSpacing.operator const char *());
    }
  }
  void PrintSpacing::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("print-spacing")) {
      _printSpacing = YesNoEnum(attr.as_string());
      _hasPrintSpacing = true;
    }
  }
}
