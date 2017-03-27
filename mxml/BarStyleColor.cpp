#include "BarStyleColor.h"
#include <cstring>

namespace mxml
{
  BarStyleColor::BarStyleColor() {}

  void BarStyleColor::ostreamAttrs(pugi::xml_node& self) const
  {
    Color::ostreamAttrs(self);
  }
  void BarStyleColor::istreamAttrs(const pugi::xml_node& self)
  {
    Color::istreamAttrs(self);
  }
}
