#include "Accord.h"
#include <cstring>
#include "TuningStep.h"
#include "TuningAlter.h"
#include "TuningOctave.h"

namespace mxml
{
  Accord::Accord() {}
  TuningStepPtr Accord::getTuningStep() const { return _tuningStepPtr; }
  void Accord::setTuningStep(const TuningStepPtr& value) { _tuningStepPtr = value; value->setParent(shared_from_this()); }
  TuningAlterPtr Accord::getTuningAlter() const { return _tuningAlterPtr; }
  void Accord::setTuningAlter(const TuningAlterPtr& value) { _tuningAlterPtr = value; value->setParent(shared_from_this()); }
  TuningOctavePtr Accord::getTuningOctave() const { return _tuningOctavePtr; }
  void Accord::setTuningOctave(const TuningOctavePtr& value) { _tuningOctavePtr = value; value->setParent(shared_from_this()); }
  bool Accord::hasString() const { return _hasString; }
  void Accord::hasString(bool value) { _hasString = value; }
  int Accord::string() const { return _string; }
  void Accord::string(int value) { _string = value; }

  void Accord::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasString) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _string);
      self.append_attribute("string").set_value(str);
    }
  }
  void Accord::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("string")) {
      _string = attr.as_int();
      _hasString = true;
    }
  }
  void Accord::ostreamContents(pugi::xml_node& self) const
  {
    if(_tuningStepPtr) {
      auto child = self.append_child("tuning-step");
      _tuningStepPtr->ostream(child);
    }
    if(_tuningAlterPtr) {
      auto child = self.append_child("tuning-alter");
      _tuningAlterPtr->ostream(child);
    }
    if(_tuningOctavePtr) {
      auto child = self.append_child("tuning-octave");
      _tuningOctavePtr->ostream(child);
    }
  }
  void Accord::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "tuning-step")==0) {
        auto tuningStepPtr = std::make_shared<TuningStep>();
        tuningStepPtr->istream(child);
        setTuningStep(tuningStepPtr);
      }
      else if(strcmp(child.name(), "tuning-alter")==0) {
        auto tuningAlterPtr = std::make_shared<TuningAlter>();
        tuningAlterPtr->istream(child);
        setTuningAlter(tuningAlterPtr);
      }
      else if(strcmp(child.name(), "tuning-octave")==0) {
        auto tuningOctavePtr = std::make_shared<TuningOctave>();
        tuningOctavePtr->istream(child);
        setTuningOctave(tuningOctavePtr);
      }
    }
  }
}
