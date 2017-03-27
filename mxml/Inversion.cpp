#include "Inversion.h"
#include <cstring>

namespace mxml
{
  Inversion::Inversion() {}

  void Inversion::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
  }
  void Inversion::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
  }
}
