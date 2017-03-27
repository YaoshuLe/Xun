#include "GroupName.h"
#include <cstring>

namespace mxml
{
  GroupName::GroupName() {}

  void GroupName::ostreamAttrs(pugi::xml_node& self) const
  {
    GroupNameText::ostreamAttrs(self);
  }
  void GroupName::istreamAttrs(const pugi::xml_node& self)
  {
    GroupNameText::istreamAttrs(self);
  }
}
