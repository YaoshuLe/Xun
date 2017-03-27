#include "StaffTuning.h"
#include <cstring>
#include "TuningStep.h"
#include "TuningAlter.h"
#include "TuningOctave.h"

namespace mxml
{
  StaffTuning::StaffTuning() {}
  TuningStepPtr StaffTuning::getTuningStep() const { return _tuningStepPtr; }
  void StaffTuning::setTuningStep(const TuningStepPtr& value) { _tuningStepPtr = value; value->setParent(shared_from_this()); }
  TuningAlterPtr StaffTuning::getTuningAlter() const { return _tuningAlterPtr; }
  void StaffTuning::setTuningAlter(const TuningAlterPtr& value) { _tuningAlterPtr = value; value->setParent(shared_from_this()); }
  TuningOctavePtr StaffTuning::getTuningOctave() const { return _tuningOctavePtr; }
  void StaffTuning::setTuningOctave(const TuningOctavePtr& value) { _tuningOctavePtr = value; value->setParent(shared_from_this()); }
  bool StaffTuning::hasLine() const { return _hasLine; }
  void StaffTuning::hasLine(bool value) { _hasLine = value; }
  int StaffTuning::line() const { return _line; }
  void StaffTuning::line(int value) { _line = value; }

  void StaffTuning::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasLine) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _line);
      self.append_attribute("line").set_value(str);
    }
  }
  void StaffTuning::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("line")) {
      _line = attr.as_int();
      _hasLine = true;
    }
  }
  void StaffTuning::ostreamContents(pugi::xml_node& self) const
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
  void StaffTuning::istreamContents(const pugi::xml_node& self)
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
