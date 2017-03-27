#include "MeasureLayout.h"
#include <cstring>
#include "MeasureDistance.h"

namespace mxml
{
  MeasureLayout::MeasureLayout() {}
  MeasureDistancePtr MeasureLayout::getMeasureDistance() const { return _measureDistancePtr; }
  void MeasureLayout::setMeasureDistance(const MeasureDistancePtr& value) { _measureDistancePtr = value; value->setParent(shared_from_this()); }

  void MeasureLayout::ostreamContents(pugi::xml_node& self) const
  {
    if(_measureDistancePtr) {
      auto child = self.append_child("measure-distance");
      _measureDistancePtr->ostream(child);
    }
  }
  void MeasureLayout::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "measure-distance")==0) {
        auto measureDistancePtr = std::make_shared<MeasureDistance>();
        measureDistancePtr->istream(child);
        setMeasureDistance(measureDistancePtr);
      }
    }
  }
}
