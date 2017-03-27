#include "TupletNumber.h"
#include <cstring>

namespace mxml
{
  TupletNumber::TupletNumber() {}

  void TupletNumber::ostreamAttrs(pugi::xml_node& self) const
  {
    Font::ostreamAttrs(self);
    Color::ostreamAttrs(self);
  }
  void TupletNumber::istreamAttrs(const pugi::xml_node& self)
  {
    Font::istreamAttrs(self);
    Color::istreamAttrs(self);
  }
}
