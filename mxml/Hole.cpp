#include "Hole.h"
#include <cstring>
#include "HoleType.h"
#include "HoleClosed.h"
#include "HoleShape.h"

namespace mxml
{
  Hole::Hole() {}
  HoleTypePtr Hole::getHoleType() const { return _holeTypePtr; }
  void Hole::setHoleType(const HoleTypePtr& value) { _holeTypePtr = value; value->setParent(shared_from_this()); }
  HoleClosedPtr Hole::getHoleClosed() const { return _holeClosedPtr; }
  void Hole::setHoleClosed(const HoleClosedPtr& value) { _holeClosedPtr = value; value->setParent(shared_from_this()); }
  HoleShapePtr Hole::getHoleShape() const { return _holeShapePtr; }
  void Hole::setHoleShape(const HoleShapePtr& value) { _holeShapePtr = value; value->setParent(shared_from_this()); }

  void Hole::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
  }
  void Hole::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
  }
  void Hole::ostreamContents(pugi::xml_node& self) const
  {
    if(_holeTypePtr) {
      auto child = self.append_child("hole-type");
      _holeTypePtr->ostream(child);
    }
    if(_holeClosedPtr) {
      auto child = self.append_child("hole-closed");
      _holeClosedPtr->ostream(child);
    }
    if(_holeShapePtr) {
      auto child = self.append_child("hole-shape");
      _holeShapePtr->ostream(child);
    }
  }
  void Hole::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "hole-type")==0) {
        auto holeTypePtr = std::make_shared<HoleType>();
        holeTypePtr->istream(child);
        setHoleType(holeTypePtr);
      }
      else if(strcmp(child.name(), "hole-closed")==0) {
        auto holeClosedPtr = std::make_shared<HoleClosed>();
        holeClosedPtr->istream(child);
        setHoleClosed(holeClosedPtr);
      }
      else if(strcmp(child.name(), "hole-shape")==0) {
        auto holeShapePtr = std::make_shared<HoleShape>();
        holeShapePtr->istream(child);
        setHoleShape(holeShapePtr);
      }
    }
  }
}
