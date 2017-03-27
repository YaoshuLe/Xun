#ifndef LINE_SHAPE_H
#define LINE_SHAPE_H
#include "AttrGroup.h"

namespace mxml
{
  class LineShape: public AttrGroup
  {
  public:
    LineShape();
    bool hasLineShape() const;
    void hasLineShape(bool value);
    LineShapeEnum lineShape() const;
    void lineShape(LineShapeEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasLineShape {false};
    LineShapeEnum _lineShape;
  };
}
#endif //LINE_SHAPE_H
