#include "AccidentalMark.h"
#include <cstring>

namespace mxml
{
  AccidentalMark::AccidentalMark() {}

  void AccidentalMark::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
  }
  void AccidentalMark::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
  }
}
