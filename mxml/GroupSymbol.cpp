#include "GroupSymbol.h"
#include <cstring>

namespace mxml
{
  GroupSymbol::GroupSymbol() {}

  void GroupSymbol::ostreamAttrs(pugi::xml_node& self) const
  {
    Position::ostreamAttrs(self);
    Color::ostreamAttrs(self);
  }
  void GroupSymbol::istreamAttrs(const pugi::xml_node& self)
  {
    Position::istreamAttrs(self);
    Color::istreamAttrs(self);
  }
}
