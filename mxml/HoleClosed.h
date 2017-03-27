#ifndef HOLE_CLOSED_H
#define HOLE_CLOSED_H
#include "Element.h"

namespace mxml
{
  class HoleClosed: public Value<HoleClosedValueEnum>
  {
  public:
    HoleClosed();
    virtual const char* tagname() const { return "hole-closed"; }
    bool hasLocation() const;
    void hasLocation(bool value);
    HoleClosedLocationEnum location() const;
    void location(HoleClosedLocationEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasLocation {false};
    HoleClosedLocationEnum _location;
  };
}
#endif //HOLE_CLOSED_H
