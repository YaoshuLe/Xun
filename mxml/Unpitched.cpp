#include "Unpitched.h"
#include <cstring>
#include "DisplayStep.h"
#include "DisplayOctave.h"

namespace mxml
{
  Unpitched::Unpitched() {}
  DisplayStepPtr Unpitched::getDisplayStep() const { return _displayStepPtr; }
  void Unpitched::setDisplayStep(const DisplayStepPtr& value) { _displayStepPtr = value; value->setParent(shared_from_this()); }
  DisplayOctavePtr Unpitched::getDisplayOctave() const { return _displayOctavePtr; }
  void Unpitched::setDisplayOctave(const DisplayOctavePtr& value) { _displayOctavePtr = value; value->setParent(shared_from_this()); }

  void Unpitched::ostreamContents(pugi::xml_node& self) const
  {
    if(_displayStepPtr) {
      auto child = self.append_child("display-step");
      _displayStepPtr->ostream(child);
    }
    if(_displayOctavePtr) {
      auto child = self.append_child("display-octave");
      _displayOctavePtr->ostream(child);
    }
  }
  void Unpitched::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "display-step")==0) {
        auto displayStepPtr = std::make_shared<DisplayStep>();
        displayStepPtr->istream(child);
        setDisplayStep(displayStepPtr);
      }
      else if(strcmp(child.name(), "display-octave")==0) {
        auto displayOctavePtr = std::make_shared<DisplayOctave>();
        displayOctavePtr->istream(child);
        setDisplayOctave(displayOctavePtr);
      }
    }
  }
}
