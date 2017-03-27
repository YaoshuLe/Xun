#include "PedalTuning.h"
#include <cstring>
#include "PedalStep.h"
#include "PedalAlter.h"

namespace mxml
{
  PedalTuning::PedalTuning() {}
  PedalStepPtr PedalTuning::getPedalStep() const { return _pedalStepPtr; }
  void PedalTuning::setPedalStep(const PedalStepPtr& value) { _pedalStepPtr = value; value->setParent(shared_from_this()); }
  PedalAlterPtr PedalTuning::getPedalAlter() const { return _pedalAlterPtr; }
  void PedalTuning::setPedalAlter(const PedalAlterPtr& value) { _pedalAlterPtr = value; value->setParent(shared_from_this()); }

  void PedalTuning::ostreamContents(pugi::xml_node& self) const
  {
    if(_pedalStepPtr) {
      auto child = self.append_child("pedal-step");
      _pedalStepPtr->ostream(child);
    }
    if(_pedalAlterPtr) {
      auto child = self.append_child("pedal-alter");
      _pedalAlterPtr->ostream(child);
    }
  }
  void PedalTuning::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "pedal-step")==0) {
        auto pedalStepPtr = std::make_shared<PedalStep>();
        pedalStepPtr->istream(child);
        setPedalStep(pedalStepPtr);
      }
      else if(strcmp(child.name(), "pedal-alter")==0) {
        auto pedalAlterPtr = std::make_shared<PedalAlter>();
        pedalAlterPtr->istream(child);
        setPedalAlter(pedalAlterPtr);
      }
    }
  }
}
