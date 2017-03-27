#include "AccidentalText.h"
#include <cstring>

namespace mxml
{
  AccidentalText::AccidentalText() {}

  void AccidentalText::ostreamAttrs(pugi::xml_node& self) const
  {
    TextFormatting::ostreamAttrs(self);
  }
  void AccidentalText::istreamAttrs(const pugi::xml_node& self)
  {
    TextFormatting::istreamAttrs(self);
  }
}
