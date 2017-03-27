#include "EmptyPlacement.h"
#include <cstring>

namespace mxml
{
  EmptyPlacement::EmptyPlacement() {}

  void EmptyPlacement::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
  }
  void EmptyPlacement::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
  }
}
