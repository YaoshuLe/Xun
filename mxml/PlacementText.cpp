#include "PlacementText.h"
#include <cstring>

namespace mxml
{
  PlacementText::PlacementText() {}

  void PlacementText::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
  }
  void PlacementText::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
  }
}
