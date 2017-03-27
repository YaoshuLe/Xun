#include "Fret.h"
#include <cstring>

namespace mxml
{
  Fret::Fret() {}

  void Fret::ostreamAttrs(pugi::xml_node& self) const
  {
    Font::ostreamAttrs(self);
    Color::ostreamAttrs(self);
  }
  void Fret::istreamAttrs(const pugi::xml_node& self)
  {
    Font::istreamAttrs(self);
    Color::istreamAttrs(self);
  }
}
