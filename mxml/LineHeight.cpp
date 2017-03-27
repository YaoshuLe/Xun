#include "LineHeight.h"
#include <cstring>

namespace mxml
{
  LineHeight::LineHeight() {}
  bool LineHeight::hasLineHeight() const { return _hasLineHeight; }
  void LineHeight::hasLineHeight(bool value) { _hasLineHeight = value; }
  NumberOrNormalEnum LineHeight::lineHeight() const { return _lineHeight; }
  void LineHeight::lineHeight(NumberOrNormalEnum value) { _lineHeight = value; }

  void LineHeight::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasLineHeight) {
      self.append_attribute("line-height").set_value(_lineHeight.operator const char *());
    }
  }
  void LineHeight::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("line-height")) {
      _lineHeight = NumberOrNormalEnum(attr.as_string());
      _hasLineHeight = true;
    }
  }
}
