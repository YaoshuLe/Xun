#include "EmptyFont.h"
#include <cstring>

namespace mxml
{
  EmptyFont::EmptyFont() {}

  void EmptyFont::ostreamAttrs(pugi::xml_node& self) const
  {
    Font::ostreamAttrs(self);
  }
  void EmptyFont::istreamAttrs(const pugi::xml_node& self)
  {
    Font::istreamAttrs(self);
  }
}
