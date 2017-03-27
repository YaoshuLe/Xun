#include "Stem.h"
#include <cstring>

namespace mxml
{
  Stem::Stem() {}

  void Stem::ostreamAttrs(pugi::xml_node& self) const
  {
    YPosition::ostreamAttrs(self);
    Color::ostreamAttrs(self);
  }
  void Stem::istreamAttrs(const pugi::xml_node& self)
  {
    YPosition::istreamAttrs(self);
    Color::istreamAttrs(self);
  }
}
