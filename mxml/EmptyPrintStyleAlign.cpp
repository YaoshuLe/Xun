#include "EmptyPrintStyleAlign.h"
#include <cstring>

namespace mxml
{
  EmptyPrintStyleAlign::EmptyPrintStyleAlign() {}

  void EmptyPrintStyleAlign::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyleAlign::ostreamAttrs(self);
  }
  void EmptyPrintStyleAlign::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyleAlign::istreamAttrs(self);
  }
}
