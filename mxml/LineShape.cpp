#include "LineShape.h"
#include <cstring>

namespace mxml
{
  LineShape::LineShape() {}
  bool LineShape::hasLineShape() const { return _hasLineShape; }
  void LineShape::hasLineShape(bool value) { _hasLineShape = value; }
  LineShapeEnum LineShape::lineShape() const { return _lineShape; }
  void LineShape::lineShape(LineShapeEnum value) { _lineShape = value; }

  void LineShape::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasLineShape) {
      self.append_attribute("line-shape").set_value(_lineShape.operator const char *());
    }
  }
  void LineShape::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("line-shape")) {
      _lineShape = LineShapeEnum(attr.as_string());
      _hasLineShape = true;
    }
  }
}
