#ifndef INVERSION_H
#define INVERSION_H
#include "Element.h"
#include "PrintStyle.h"

namespace mxml
{
  class Inversion: public Value<int>, public PrintStyle
  {
  public:
    Inversion();
    virtual const char* tagname() const { return "inversion"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //INVERSION_H
