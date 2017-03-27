#ifndef TUPLET_TYPE_H
#define TUPLET_TYPE_H
#include "Element.h"
#include "Font.h"
#include "Color.h"

namespace mxml
{
  class TupletType: public Value<NoteTypeValueEnum>, public Font, public Color
  {
  public:
    TupletType();
    virtual const char* tagname() const { return "tuplet-type"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //TUPLET_TYPE_H
