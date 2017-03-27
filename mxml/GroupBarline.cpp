#include "GroupBarline.h"
#include <cstring>

namespace mxml
{
  GroupBarline::GroupBarline() {}

  void GroupBarline::ostreamAttrs(pugi::xml_node& self) const
  {
    Color::ostreamAttrs(self);
  }
  void GroupBarline::istreamAttrs(const pugi::xml_node& self)
  {
    Color::istreamAttrs(self);
  }
}
