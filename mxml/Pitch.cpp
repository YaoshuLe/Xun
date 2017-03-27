#include "Pitch.h"
#include <cstring>
#include "Step.h"
#include "Alter.h"
#include "Octave.h"

namespace mxml
{
  Pitch::Pitch() {}
  StepPtr Pitch::getStep() const { return _stepPtr; }
  void Pitch::setStep(const StepPtr& value) { _stepPtr = value; value->setParent(shared_from_this()); }
  AlterPtr Pitch::getAlter() const { return _alterPtr; }
  void Pitch::setAlter(const AlterPtr& value) { _alterPtr = value; value->setParent(shared_from_this()); }
  OctavePtr Pitch::getOctave() const { return _octavePtr; }
  void Pitch::setOctave(const OctavePtr& value) { _octavePtr = value; value->setParent(shared_from_this()); }

  void Pitch::ostreamContents(pugi::xml_node& self) const
  {
    if(_stepPtr) {
      auto child = self.append_child("step");
      _stepPtr->ostream(child);
    }
    if(_alterPtr) {
      auto child = self.append_child("alter");
      _alterPtr->ostream(child);
    }
    if(_octavePtr) {
      auto child = self.append_child("octave");
      _octavePtr->ostream(child);
    }
  }
  void Pitch::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "step")==0) {
        auto stepPtr = std::make_shared<Step>();
        stepPtr->istream(child);
        setStep(stepPtr);
      }
      else if(strcmp(child.name(), "alter")==0) {
        auto alterPtr = std::make_shared<Alter>();
        alterPtr->istream(child);
        setAlter(alterPtr);
      }
      else if(strcmp(child.name(), "octave")==0) {
        auto octavePtr = std::make_shared<Octave>();
        octavePtr->istream(child);
        setOctave(octavePtr);
      }
    }
  }
}
