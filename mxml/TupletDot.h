#ifndef TUPLET_DOT_H
#define TUPLET_DOT_H
#include "Element.h"
#include "Font.h"
#include "Color.h"

namespace mxml
{
  class TupletDot: public Empty, public Font, public Color
  {
  public:
    TupletDot();
    virtual const char* tagname() const { return "tuplet-dot"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //TUPLET_DOT_H
