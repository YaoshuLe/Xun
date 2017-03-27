#ifndef HOLE_H
#define HOLE_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class HoleType;
  using HoleTypePtr = std::shared_ptr<HoleType>;
  class HoleClosed;
  using HoleClosedPtr = std::shared_ptr<HoleClosed>;
  class HoleShape;
  using HoleShapePtr = std::shared_ptr<HoleShape>;

  class Hole: public Element, public PrintStyle, public Placement
  {
  public:
    Hole();
    virtual const char* tagname() const { return "hole"; }
    HoleTypePtr getHoleType() const;
    void setHoleType(const HoleTypePtr& value);
    HoleClosedPtr getHoleClosed() const;
    void setHoleClosed(const HoleClosedPtr& value);
    HoleShapePtr getHoleShape() const;
    void setHoleShape(const HoleShapePtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    HoleTypePtr _holeTypePtr;
    HoleClosedPtr _holeClosedPtr;
    HoleShapePtr _holeShapePtr;
  };
}
#endif //HOLE_H
