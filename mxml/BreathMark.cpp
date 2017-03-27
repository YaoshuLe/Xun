#include "BreathMark.h"
#include <cstring>

namespace mxml
{
  BreathMark::BreathMark() {}

  void BreathMark::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
  }
  void BreathMark::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
  }
}
