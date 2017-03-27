#include "TupletDot.h"
#include <cstring>

namespace mxml
{
  TupletDot::TupletDot() {}

  void TupletDot::ostreamAttrs(pugi::xml_node& self) const
  {
    Font::ostreamAttrs(self);
    Color::ostreamAttrs(self);
  }
  void TupletDot::istreamAttrs(const pugi::xml_node& self)
  {
    Font::istreamAttrs(self);
    Color::istreamAttrs(self);
  }
}
