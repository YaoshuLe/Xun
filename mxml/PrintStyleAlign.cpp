#include "PrintStyleAlign.h"
#include <cstring>

namespace mxml
{
  PrintStyleAlign::PrintStyleAlign() {}

  void PrintStyleAlign::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Halign::ostreamAttrs(self);
    Valign::ostreamAttrs(self);
  }
  void PrintStyleAlign::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Halign::istreamAttrs(self);
    Valign::istreamAttrs(self);
  }
}
