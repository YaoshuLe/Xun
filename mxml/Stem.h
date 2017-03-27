#ifndef STEM_H
#define STEM_H
#include "Element.h"
#include "YPosition.h"
#include "Color.h"

namespace mxml
{
  class Stem: public Value<StemValueEnum>, public YPosition, public Color
  {
  public:
    Stem();
    virtual const char* tagname() const { return "stem"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //STEM_H
