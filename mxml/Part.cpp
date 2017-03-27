#include "Part.h"
#include <cstring>
#include "Measure.h"

namespace mxml
{
  Part::Part() {}
  const MeasureSet& Part::getMeasureSet() const {  return _measureSet; }
  void Part::removeMeasure(const MeasurePtr& value) { if(value) { auto i = std::find_if(_measureSet.begin(), _measureSet.end(), [&](const MeasurePtr& item) { return item==value; }); if(i!=_measureSet.end()) _measureSet.erase(i); } }
  void Part::addMeasure(const MeasurePtr& value) { if(value) { _measureSet.push_back(value); value->setParent(shared_from_this()); } }
  void Part::clearMeasureSet() { _measureSet.clear(); }

  void Part::ostreamAttrs(pugi::xml_node& self) const
  {
    PartAttributes::ostreamAttrs(self);
  }
  void Part::istreamAttrs(const pugi::xml_node& self)
  {
    PartAttributes::istreamAttrs(self);
  }
  void Part::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _measureSet) {
      auto child = self.append_child("measure");
      item->ostream(child);
    }
  }
  void Part::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "measure")==0) {
        auto measurePtr = std::make_shared<Measure>();
        measurePtr->istream(child);
        addMeasure(measurePtr);
      }
    }
  }
}
