#include "PerMinute.h"
#include <cstring>

namespace mxml
{
  PerMinute::PerMinute() {}

  void PerMinute::ostreamAttrs(pugi::xml_node& self) const
  {
    Font::ostreamAttrs(self);
  }
  void PerMinute::istreamAttrs(const pugi::xml_node& self)
  {
    Font::istreamAttrs(self);
  }
}
