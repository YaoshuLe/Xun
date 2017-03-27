#ifndef PLACEMENT_H
#define PLACEMENT_H
#include "AttrGroup.h"

namespace mxml
{
  class Placement: public AttrGroup
  {
  public:
    Placement();
    bool hasPlacement() const;
    void hasPlacement(bool value);
    AboveBelowEnum placement() const;
    void placement(AboveBelowEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasPlacement {false};
    AboveBelowEnum _placement;
  };
}
#endif //PLACEMENT_H
