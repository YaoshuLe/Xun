#include "MeasureNumbering.h"
#include <cstring>

namespace mxml
{
  MeasureNumbering::MeasureNumbering() {}

  void MeasureNumbering::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyleAlign::ostreamAttrs(self);
  }
  void MeasureNumbering::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyleAlign::istreamAttrs(self);
  }
}
