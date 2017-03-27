#include "StaffLayout.h"
#include <cstring>
#include "StaffDistance.h"

namespace mxml
{
  StaffLayout::StaffLayout() {}
  StaffDistancePtr StaffLayout::getStaffDistance() const { return _staffDistancePtr; }
  void StaffLayout::setStaffDistance(const StaffDistancePtr& value) { _staffDistancePtr = value; value->setParent(shared_from_this()); }
  bool StaffLayout::hasNumber() const { return _hasNumber; }
  void StaffLayout::hasNumber(bool value) { _hasNumber = value; }
  int StaffLayout::number() const { return _number; }
  void StaffLayout::number(int value) { _number = value; }

  void StaffLayout::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
  }
  void StaffLayout::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
  }
  void StaffLayout::ostreamContents(pugi::xml_node& self) const
  {
    if(_staffDistancePtr) {
      auto child = self.append_child("staff-distance");
      _staffDistancePtr->ostream(child);
    }
  }
  void StaffLayout::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "staff-distance")==0) {
        auto staffDistancePtr = std::make_shared<StaffDistance>();
        staffDistancePtr->istream(child);
        setStaffDistance(staffDistancePtr);
      }
    }
  }
}
