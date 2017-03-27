#include "EmptyPrintStyle.h"
#include <cstring>

namespace mxml
{
  EmptyPrintStyle::EmptyPrintStyle() {}

  void EmptyPrintStyle::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
  }
  void EmptyPrintStyle::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
  }
}
