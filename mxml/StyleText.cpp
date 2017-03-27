#include "StyleText.h"
#include <cstring>

namespace mxml
{
  StyleText::StyleText() {}

  void StyleText::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
  }
  void StyleText::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
  }
}
