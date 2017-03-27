#include "PrintStyle.h"
#include <cstring>

namespace mxml
{
  PrintStyle::PrintStyle() {}

  void PrintStyle::ostreamAttrs(pugi::xml_node& self) const
  {
    Position::ostreamAttrs(self);
    Font::ostreamAttrs(self);
    Color::ostreamAttrs(self);
  }
  void PrintStyle::istreamAttrs(const pugi::xml_node& self)
  {
    Position::istreamAttrs(self);
    Font::istreamAttrs(self);
    Color::istreamAttrs(self);
  }
}
