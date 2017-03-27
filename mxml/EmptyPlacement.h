#ifndef EMPTY_PLACEMENT_H
#define EMPTY_PLACEMENT_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class EmptyPlacement: public Empty, public PrintStyle, public Placement
  {
  public:
    EmptyPlacement();
    virtual const char* tagname() const { return "empty-placement"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //EMPTY_PLACEMENT_H
