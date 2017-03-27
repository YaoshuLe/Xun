#include "String.h"
#include <cstring>

namespace mxml
{
  String::String() {}

  void String::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
  }
  void String::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
  }
}
