#ifndef LINE_TYPE_H
#define LINE_TYPE_H
#include "AttrGroup.h"

namespace mxml
{
  class LineType: public AttrGroup
  {
  public:
    LineType();
    bool hasLineType() const;
    void hasLineType(bool value);
    LineTypeEnum lineType() const;
    void lineType(LineTypeEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasLineType {false};
    LineTypeEnum _lineType;
  };
}
#endif //LINE_TYPE_H
