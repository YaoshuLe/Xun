#include "EmptyPrintObjectStyleAlign.h"
#include <cstring>

namespace mxml
{
  EmptyPrintObjectStyleAlign::EmptyPrintObjectStyleAlign() {}

  void EmptyPrintObjectStyleAlign::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintObject::ostreamAttrs(self);
    PrintStyleAlign::ostreamAttrs(self);
  }
  void EmptyPrintObjectStyleAlign::istreamAttrs(const pugi::xml_node& self)
  {
    PrintObject::istreamAttrs(self);
    PrintStyleAlign::istreamAttrs(self);
  }
}
