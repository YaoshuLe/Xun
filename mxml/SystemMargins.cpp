#include "SystemMargins.h"
#include <cstring>
#include "LeftMargin.h"
#include "RightMargin.h"

namespace mxml
{
  SystemMargins::SystemMargins() {}
  LeftMarginPtr SystemMargins::getLeftMargin() const { return _leftMarginPtr; }
  void SystemMargins::setLeftMargin(const LeftMarginPtr& value) { _leftMarginPtr = value; value->setParent(shared_from_this()); }
  RightMarginPtr SystemMargins::getRightMargin() const { return _rightMarginPtr; }
  void SystemMargins::setRightMargin(const RightMarginPtr& value) { _rightMarginPtr = value; value->setParent(shared_from_this()); }

  void SystemMargins::ostreamContents(pugi::xml_node& self) const
  {
    if(_leftMarginPtr) {
      auto child = self.append_child("left-margin");
      _leftMarginPtr->ostream(child);
    }
    if(_rightMarginPtr) {
      auto child = self.append_child("right-margin");
      _rightMarginPtr->ostream(child);
    }
  }
  void SystemMargins::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "left-margin")==0) {
        auto leftMarginPtr = std::make_shared<LeftMargin>();
        leftMarginPtr->istream(child);
        setLeftMargin(leftMarginPtr);
      }
      else if(strcmp(child.name(), "right-margin")==0) {
        auto rightMarginPtr = std::make_shared<RightMargin>();
        rightMarginPtr->istream(child);
        setRightMargin(rightMarginPtr);
      }
    }
  }
}
