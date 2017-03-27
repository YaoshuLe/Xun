#ifndef ORIENTATION_H
#define ORIENTATION_H
#include "AttrGroup.h"

namespace mxml
{
  class Orientation: public AttrGroup
  {
  public:
    Orientation();
    bool hasOrientation() const;
    void hasOrientation(bool value);
    OverUnderEnum orientation() const;
    void orientation(OverUnderEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasOrientation {false};
    OverUnderEnum _orientation;
  };
}
#endif //ORIENTATION_H
