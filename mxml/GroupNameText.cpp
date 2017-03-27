#include "GroupNameText.h"
#include <cstring>

namespace mxml
{
  GroupNameText::GroupNameText() {}

  void GroupNameText::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Justify::ostreamAttrs(self);
  }
  void GroupNameText::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Justify::istreamAttrs(self);
  }
}
