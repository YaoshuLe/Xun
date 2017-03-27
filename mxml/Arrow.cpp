#include "Arrow.h"
#include <cstring>
#include "ArrowDirection.h"
#include "ArrowStyle.h"
#include "CircularArrow.h"

namespace mxml
{
  Arrow::Arrow() {}
  ArrowDirectionPtr Arrow::getArrowDirection() const { return _arrowDirectionPtr; }
  void Arrow::setArrowDirection(const ArrowDirectionPtr& value) { _arrowDirectionPtr = value; value->setParent(shared_from_this()); }
  ArrowStylePtr Arrow::getArrowStyle() const { return _arrowStylePtr; }
  void Arrow::setArrowStyle(const ArrowStylePtr& value) { _arrowStylePtr = value; value->setParent(shared_from_this()); }
  CircularArrowPtr Arrow::getCircularArrow() const { return _circularArrowPtr; }
  void Arrow::setCircularArrow(const CircularArrowPtr& value) { _circularArrowPtr = value; value->setParent(shared_from_this()); }

  void Arrow::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
  }
  void Arrow::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
  }
  void Arrow::ostreamContents(pugi::xml_node& self) const
  {
    if(_arrowDirectionPtr) {
      auto child = self.append_child("arrow-direction");
      _arrowDirectionPtr->ostream(child);
      if(_arrowStylePtr) {
        auto child = self.append_child("arrow-style");
        _arrowStylePtr->ostream(child);
      }
    }
    else if(_circularArrowPtr) {
      auto child = self.append_child("circular-arrow");
      _circularArrowPtr->ostream(child);
    }
  }
  void Arrow::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "arrow-direction")==0) {
        auto arrowDirectionPtr = std::make_shared<ArrowDirection>();
        arrowDirectionPtr->istream(child);
        setArrowDirection(arrowDirectionPtr);
      }
      else if(strcmp(child.name(), "arrow-style")==0) {
        auto arrowStylePtr = std::make_shared<ArrowStyle>();
        arrowStylePtr->istream(child);
        setArrowStyle(arrowStylePtr);
      }
      else if(strcmp(child.name(), "circular-arrow")==0) {
        auto circularArrowPtr = std::make_shared<CircularArrow>();
        circularArrowPtr->istream(child);
        setCircularArrow(circularArrowPtr);
      }
    }
  }
}
