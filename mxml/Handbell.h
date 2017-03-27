#ifndef HANDBELL_H
#define HANDBELL_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class Handbell: public Value<HandbellValueEnum>, public PrintStyle, public Placement
  {
  public:
    Handbell();
    virtual const char* tagname() const { return "handbell"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //HANDBELL_H
