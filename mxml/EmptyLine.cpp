#include "EmptyLine.h"
#include <cstring>

namespace mxml
{
  EmptyLine::EmptyLine() {}

  void EmptyLine::ostreamAttrs(pugi::xml_node& self) const
  {
    LineShape::ostreamAttrs(self);
    LineType::ostreamAttrs(self);
    DashedFormatting::ostreamAttrs(self);
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
  }
  void EmptyLine::istreamAttrs(const pugi::xml_node& self)
  {
    LineShape::istreamAttrs(self);
    LineType::istreamAttrs(self);
    DashedFormatting::istreamAttrs(self);
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
  }
}
