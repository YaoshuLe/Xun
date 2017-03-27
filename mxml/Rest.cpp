#include "Rest.h"
#include <cstring>
#include "DisplayStep.h"
#include "DisplayOctave.h"

namespace mxml
{
  Rest::Rest() {}
  DisplayStepPtr Rest::getDisplayStep() const { return _displayStepPtr; }
  void Rest::setDisplayStep(const DisplayStepPtr& value) { _displayStepPtr = value; value->setParent(shared_from_this()); }
  DisplayOctavePtr Rest::getDisplayOctave() const { return _displayOctavePtr; }
  void Rest::setDisplayOctave(const DisplayOctavePtr& value) { _displayOctavePtr = value; value->setParent(shared_from_this()); }
  bool Rest::hasMeasure() const { return _hasMeasure; }
  void Rest::hasMeasure(bool value) { _hasMeasure = value; }
  YesNoEnum Rest::measure() const { return _measure; }
  void Rest::measure(YesNoEnum value) { _measure = value; }

  void Rest::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasMeasure) {
      self.append_attribute("measure").set_value(_measure.operator const char *());
    }
  }
  void Rest::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("measure")) {
      _measure = YesNoEnum(attr.as_string());
      _hasMeasure = true;
    }
  }
  void Rest::ostreamContents(pugi::xml_node& self) const
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
  void Rest::istreamContents(const pugi::xml_node& self)
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
