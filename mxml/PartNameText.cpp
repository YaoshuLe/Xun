#include "PartNameText.h"
#include <cstring>

namespace mxml
{
  PartNameText::PartNameText() {}

  void PartNameText::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    PrintObject::ostreamAttrs(self);
    Justify::ostreamAttrs(self);
  }
  void PartNameText::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    PrintObject::istreamAttrs(self);
    Justify::istreamAttrs(self);
  }
}
