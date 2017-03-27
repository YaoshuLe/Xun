#include "TimeSignature.h"
#include <cstring>
#include "Beats.h"
#include "BeatType.h"

namespace mxml
{
  TimeSignature::TimeSignature() {}
  BeatsPtr TimeSignature::getBeats() const { return _beatsPtr; }
  void TimeSignature::setBeats(const BeatsPtr& value) { _beatsPtr = value; value->setParent(shared_from_this()); }
  BeatTypePtr TimeSignature::getBeatType() const { return _beatTypePtr; }
  void TimeSignature::setBeatType(const BeatTypePtr& value) { _beatTypePtr = value; value->setParent(shared_from_this()); }

  void TimeSignature::ostreamContents(pugi::xml_node& self) const
  {
    if(_beatsPtr) {
      auto child = self.append_child("beats");
      _beatsPtr->ostream(child);
    }
    if(_beatTypePtr) {
      auto child = self.append_child("beat-type");
      _beatTypePtr->ostream(child);
    }
  }
  void TimeSignature::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "beats")==0) {
        auto beatsPtr = std::make_shared<Beats>();
        beatsPtr->istream(child);
        setBeats(beatsPtr);
      }
      else if(strcmp(child.name(), "beat-type")==0) {
        auto beatTypePtr = std::make_shared<BeatType>();
        beatTypePtr->istream(child);
        setBeatType(beatTypePtr);
      }
    }
  }
}
