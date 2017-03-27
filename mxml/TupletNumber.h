#ifndef TUPLET_NUMBER_H
#define TUPLET_NUMBER_H
#include "Element.h"
#include "Font.h"
#include "Color.h"

namespace mxml
{
  class TupletNumber: public Value<int>, public Font, public Color
  {
  public:
    TupletNumber();
    virtual const char* tagname() const { return "tuplet-number"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //TUPLET_NUMBER_H
