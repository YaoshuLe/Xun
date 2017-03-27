#include "FormattedText.h"
#include <cstring>

namespace mxml
{
  FormattedText::FormattedText() {}

  void FormattedText::ostreamAttrs(pugi::xml_node& self) const
  {
    TextFormatting::ostreamAttrs(self);
  }
  void FormattedText::istreamAttrs(const pugi::xml_node& self)
  {
    TextFormatting::istreamAttrs(self);
  }
}
