#include "SystemDividers.h"
#include <cstring>
#include "LeftDivider.h"
#include "RightDivider.h"

namespace mxml
{
  SystemDividers::SystemDividers() {}
  LeftDividerPtr SystemDividers::getLeftDivider() const { return _leftDividerPtr; }
  void SystemDividers::setLeftDivider(const LeftDividerPtr& value) { _leftDividerPtr = value; value->setParent(shared_from_this()); }
  RightDividerPtr SystemDividers::getRightDivider() const { return _rightDividerPtr; }
  void SystemDividers::setRightDivider(const RightDividerPtr& value) { _rightDividerPtr = value; value->setParent(shared_from_this()); }

  void SystemDividers::ostreamContents(pugi::xml_node& self) const
  {
    if(_leftDividerPtr) {
      auto child = self.append_child("left-divider");
      _leftDividerPtr->ostream(child);
    }
    if(_rightDividerPtr) {
      auto child = self.append_child("right-divider");
      _rightDividerPtr->ostream(child);
    }
  }
  void SystemDividers::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "left-divider")==0) {
        auto leftDividerPtr = std::make_shared<LeftDivider>();
        leftDividerPtr->istream(child);
        setLeftDivider(leftDividerPtr);
      }
      else if(strcmp(child.name(), "right-divider")==0) {
        auto rightDividerPtr = std::make_shared<RightDivider>();
        rightDividerPtr->istream(child);
        setRightDivider(rightDividerPtr);
      }
    }
  }
}
