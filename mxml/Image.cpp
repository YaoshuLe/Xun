#include "Image.h"
#include <cstring>

namespace mxml
{
  Image::Image() {}

  void Image::ostreamAttrs(pugi::xml_node& self) const
  {
    ImageAttributes::ostreamAttrs(self);
  }
  void Image::istreamAttrs(const pugi::xml_node& self)
  {
    ImageAttributes::istreamAttrs(self);
  }
}
