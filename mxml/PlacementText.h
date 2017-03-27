#ifndef PLACEMENT_TEXT_H
#define PLACEMENT_TEXT_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class PlacementText: public Value<std::string>, public PrintStyle, public Placement
  {
  public:
    PlacementText();
    virtual const char* tagname() const { return "placement-text"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //PLACEMENT_TEXT_H
