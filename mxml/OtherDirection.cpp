#include "OtherDirection.h"
#include <cstring>

namespace mxml
{
  OtherDirection::OtherDirection() {}

  void OtherDirection::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintObject::ostreamAttrs(self);
    PrintStyleAlign::ostreamAttrs(self);
  }
  void OtherDirection::istreamAttrs(const pugi::xml_node& self)
  {
    PrintObject::istreamAttrs(self);
    PrintStyleAlign::istreamAttrs(self);
  }
}
