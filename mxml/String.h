#ifndef STRING_H
#define STRING_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class String: public Value<int>, public PrintStyle, public Placement
  {
  public:
    String();
    virtual const char* tagname() const { return "string"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //STRING_H
