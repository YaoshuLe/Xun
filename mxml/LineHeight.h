#ifndef LINE_HEIGHT_H
#define LINE_HEIGHT_H
#include "AttrGroup.h"

namespace mxml
{
  class LineHeight: public AttrGroup
  {
  public:
    LineHeight();
    bool hasLineHeight() const;
    void hasLineHeight(bool value);
    NumberOrNormalEnum lineHeight() const;
    void lineHeight(NumberOrNormalEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasLineHeight {false};
    NumberOrNormalEnum _lineHeight;
  };
}
#endif //LINE_HEIGHT_H
