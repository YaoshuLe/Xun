#include "PartName.h"
#include <cstring>

namespace mxml
{
  PartName::PartName() {}

  void PartName::ostreamAttrs(pugi::xml_node& self) const
  {
    PartNameText::ostreamAttrs(self);
  }
  void PartName::istreamAttrs(const pugi::xml_node& self)
  {
    PartNameText::istreamAttrs(self);
  }
}
