#ifndef EMPTY_FONT_H
#define EMPTY_FONT_H
#include "Element.h"
#include "Font.h"

namespace mxml
{
  class EmptyFont: public Empty, public Font
  {
  public:
    EmptyFont();
    virtual const char* tagname() const { return "empty-font"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //EMPTY_FONT_H
