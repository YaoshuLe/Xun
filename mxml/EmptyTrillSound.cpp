#include "EmptyTrillSound.h"
#include <cstring>

namespace mxml
{
  EmptyTrillSound::EmptyTrillSound() {}

  void EmptyTrillSound::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
    TrillSound::ostreamAttrs(self);
  }
  void EmptyTrillSound::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
    TrillSound::istreamAttrs(self);
  }
}
