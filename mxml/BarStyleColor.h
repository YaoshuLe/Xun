#ifndef BAR_STYLE_COLOR_H
#define BAR_STYLE_COLOR_H
#include "Element.h"
#include "Color.h"

namespace mxml
{
  class BarStyleColor: public Value<BarStyleEnum>, public Color
  {
  public:
    BarStyleColor();
    virtual const char* tagname() const { return "bar-style-color"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //BAR_STYLE_COLOR_H
