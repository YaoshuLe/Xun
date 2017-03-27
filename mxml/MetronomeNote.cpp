#include "MetronomeNote.h"
#include <cstring>
#include "MetronomeType.h"
#include "MetronomeDot.h"
#include "MetronomeBeam.h"
#include "MetronomeTuplet.h"

namespace mxml
{
  MetronomeNote::MetronomeNote() {}
  MetronomeTypePtr MetronomeNote::getMetronomeType() const { return _metronomeTypePtr; }
  void MetronomeNote::setMetronomeType(const MetronomeTypePtr& value) { _metronomeTypePtr = value; value->setParent(shared_from_this()); }
  const MetronomeDotSet& MetronomeNote::getMetronomeDotSet() const {  return _metronomeDotSet; }
  void MetronomeNote::removeMetronomeDot(const MetronomeDotPtr& value) { if(value) { auto i = std::find_if(_metronomeDotSet.begin(), _metronomeDotSet.end(), [&](const MetronomeDotPtr& item) { return item==value; }); if(i!=_metronomeDotSet.end()) _metronomeDotSet.erase(i); } } 
  void MetronomeNote::addMetronomeDot(const MetronomeDotPtr& value) { if(value) { _metronomeDotSet.push_back(value); value->setParent(shared_from_this()); } }
  void MetronomeNote::clearMetronomeDotSet() { _metronomeDotSet.clear(); }
  const MetronomeBeamSet& MetronomeNote::getMetronomeBeamSet() const {  return _metronomeBeamSet; }
  void MetronomeNote::removeMetronomeBeam(const MetronomeBeamPtr& value) { if(value) { auto i = std::find_if(_metronomeBeamSet.begin(), _metronomeBeamSet.end(), [&](const MetronomeBeamPtr& item) { return item==value; }); if(i!=_metronomeBeamSet.end()) _metronomeBeamSet.erase(i); } } 
  void MetronomeNote::addMetronomeBeam(const MetronomeBeamPtr& value) { if(value) { _metronomeBeamSet.push_back(value); value->setParent(shared_from_this()); } }
  void MetronomeNote::clearMetronomeBeamSet() { _metronomeBeamSet.clear(); }
  MetronomeTupletPtr MetronomeNote::getMetronomeTuplet() const { return _metronomeTupletPtr; }
  void MetronomeNote::setMetronomeTuplet(const MetronomeTupletPtr& value) { _metronomeTupletPtr = value; value->setParent(shared_from_this()); }

  void MetronomeNote::ostreamContents(pugi::xml_node& self) const
  {
    if(_metronomeTypePtr) {
      auto child = self.append_child("metronome-type");
      _metronomeTypePtr->ostream(child);
    }
    for(auto item : _metronomeDotSet) {
      auto child = self.append_child("metronome-dot");
      item->ostream(child);
    }
    for(auto item : _metronomeBeamSet) {
      auto child = self.append_child("metronome-beam");
      item->ostream(child);
    }
    if(_metronomeTupletPtr) {
      auto child = self.append_child("metronome-tuplet");
      _metronomeTupletPtr->ostream(child);
    }
  }
  void MetronomeNote::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "metronome-type")==0) {
        auto metronomeTypePtr = std::make_shared<MetronomeType>();
        metronomeTypePtr->istream(child);
        setMetronomeType(metronomeTypePtr);
      }
      else if(strcmp(child.name(), "metronome-dot")==0) {
        auto metronomeDotPtr = std::make_shared<MetronomeDot>();
        metronomeDotPtr->istream(child);
        addMetronomeDot(metronomeDotPtr);
      }
      else if(strcmp(child.name(), "metronome-beam")==0) {
        auto metronomeBeamPtr = std::make_shared<MetronomeBeam>();
        metronomeBeamPtr->istream(child);
        addMetronomeBeam(metronomeBeamPtr);
      }
      else if(strcmp(child.name(), "metronome-tuplet")==0) {
        auto metronomeTupletPtr = std::make_shared<MetronomeTuplet>();
        metronomeTupletPtr->istream(child);
        setMetronomeTuplet(metronomeTupletPtr);
      }
    }
  }
}
