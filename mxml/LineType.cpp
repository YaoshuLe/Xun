#include "LineType.h"
#include <cstring>

namespace mxml
{
  LineType::LineType() {}
  bool LineType::hasLineType() const { return _hasLineType; }
  void LineType::hasLineType(bool value) { _hasLineType = value; }
  LineTypeEnum LineType::lineType() const { return _lineType; }
  void LineType::lineType(LineTypeEnum value) { _lineType = value; }

  void LineType::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasLineType) {
      self.append_attribute("line-type").set_value(_lineType.operator const char *());
    }
  }
  void LineType::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("line-type")) {
      _lineType = LineTypeEnum(attr.as_string());
      _hasLineType = true;
    }
  }
}
