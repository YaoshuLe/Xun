#ifndef FRET_H
#define FRET_H
#include "Element.h"
#include "Font.h"
#include "Color.h"

namespace mxml
{
  class Fret: public Value<int>, public Font, public Color
  {
  public:
    Fret();
    virtual const char* tagname() const { return "fret"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //FRET_H
