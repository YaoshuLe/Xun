#include "Opus.h"
#include <cstring>

namespace mxml
{
  Opus::Opus() {}

  void Opus::ostreamAttrs(pugi::xml_node& self) const
  {
    LinkAttributes::ostreamAttrs(self);
  }
  void Opus::istreamAttrs(const pugi::xml_node& self)
  {
    LinkAttributes::istreamAttrs(self);
  }
}
