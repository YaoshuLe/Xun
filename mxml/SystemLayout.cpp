#include "SystemLayout.h"
#include <cstring>
#include "SystemMargins.h"
#include "SystemDistance.h"
#include "TopSystemDistance.h"
#include "SystemDividers.h"

namespace mxml
{
  SystemLayout::SystemLayout() {}
  SystemMarginsPtr SystemLayout::getSystemMargins() const { return _systemMarginsPtr; }
  void SystemLayout::setSystemMargins(const SystemMarginsPtr& value) { _systemMarginsPtr = value; value->setParent(shared_from_this()); }
  SystemDistancePtr SystemLayout::getSystemDistance() const { return _systemDistancePtr; }
  void SystemLayout::setSystemDistance(const SystemDistancePtr& value) { _systemDistancePtr = value; value->setParent(shared_from_this()); }
  TopSystemDistancePtr SystemLayout::getTopSystemDistance() const { return _topSystemDistancePtr; }
  void SystemLayout::setTopSystemDistance(const TopSystemDistancePtr& value) { _topSystemDistancePtr = value; value->setParent(shared_from_this()); }
  SystemDividersPtr SystemLayout::getSystemDividers() const { return _systemDividersPtr; }
  void SystemLayout::setSystemDividers(const SystemDividersPtr& value) { _systemDividersPtr = value; value->setParent(shared_from_this()); }

  void SystemLayout::ostreamContents(pugi::xml_node& self) const
  {
    if(_systemMarginsPtr) {
      auto child = self.append_child("system-margins");
      _systemMarginsPtr->ostream(child);
    }
    if(_systemDistancePtr) {
      auto child = self.append_child("system-distance");
      _systemDistancePtr->ostream(child);
    }
    if(_topSystemDistancePtr) {
      auto child = self.append_child("top-system-distance");
      _topSystemDistancePtr->ostream(child);
    }
    if(_systemDividersPtr) {
      auto child = self.append_child("system-dividers");
      _systemDividersPtr->ostream(child);
    }
  }
  void SystemLayout::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "system-margins")==0) {
        auto systemMarginsPtr = std::make_shared<SystemMargins>();
        systemMarginsPtr->istream(child);
        setSystemMargins(systemMarginsPtr);
      }
      else if(strcmp(child.name(), "system-distance")==0) {
        auto systemDistancePtr = std::make_shared<SystemDistance>();
        systemDistancePtr->istream(child);
        setSystemDistance(systemDistancePtr);
      }
      else if(strcmp(child.name(), "top-system-distance")==0) {
        auto topSystemDistancePtr = std::make_shared<TopSystemDistance>();
        topSystemDistancePtr->istream(child);
        setTopSystemDistance(topSystemDistancePtr);
      }
      else if(strcmp(child.name(), "system-dividers")==0) {
        auto systemDividersPtr = std::make_shared<SystemDividers>();
        systemDividersPtr->istream(child);
        setSystemDividers(systemDividersPtr);
      }
    }
  }
}
