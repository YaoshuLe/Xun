#include "HarpPedals.h"
#include <cstring>
#include "PedalTuning.h"

namespace mxml
{
  HarpPedals::HarpPedals() {}
  const PedalTuningSet& HarpPedals::getPedalTuningSet() const {  return _pedalTuningSet; }
  void HarpPedals::removePedalTuning(const PedalTuningPtr& value) { if(value) { auto i = std::find_if(_pedalTuningSet.begin(), _pedalTuningSet.end(), [&](const PedalTuningPtr& item) { return item==value; }); if(i!=_pedalTuningSet.end()) _pedalTuningSet.erase(i); } } 
  void HarpPedals::addPedalTuning(const PedalTuningPtr& value) { if(value) { _pedalTuningSet.push_back(value); value->setParent(shared_from_this()); } }
  void HarpPedals::clearPedalTuningSet() { _pedalTuningSet.clear(); }

  void HarpPedals::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyleAlign::ostreamAttrs(self);
  }
  void HarpPedals::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyleAlign::istreamAttrs(self);
  }
  void HarpPedals::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _pedalTuningSet) {
      auto child = self.append_child("pedal-tuning");
      item->ostream(child);
    }
  }
  void HarpPedals::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "pedal-tuning")==0) {
        auto pedalTuningPtr = std::make_shared<PedalTuning>();
        pedalTuningPtr->istream(child);
        addPedalTuning(pedalTuningPtr);
      }
    }
  }
}
