#include "TupletType.h"
#include <cstring>

namespace mxml
{
  TupletType::TupletType() {}

  void TupletType::ostreamAttrs(pugi::xml_node& self) const
  {
    Font::ostreamAttrs(self);
    Color::ostreamAttrs(self);
  }
  void TupletType::istreamAttrs(const pugi::xml_node& self)
  {
    Font::istreamAttrs(self);
    Color::istreamAttrs(self);
  }
}
