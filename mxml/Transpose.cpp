#include "Transpose.h"
#include <cstring>
#include "Diatonic.h"
#include "Chromatic.h"
#include "OctaveChange.h"
#include "Double.h"

namespace mxml
{
  Transpose::Transpose() {}
  DiatonicPtr Transpose::getDiatonic() const { return _diatonicPtr; }
  void Transpose::setDiatonic(const DiatonicPtr& value) { _diatonicPtr = value; value->setParent(shared_from_this()); }
  ChromaticPtr Transpose::getChromatic() const { return _chromaticPtr; }
  void Transpose::setChromatic(const ChromaticPtr& value) { _chromaticPtr = value; value->setParent(shared_from_this()); }
  OctaveChangePtr Transpose::getOctaveChange() const { return _octaveChangePtr; }
  void Transpose::setOctaveChange(const OctaveChangePtr& value) { _octaveChangePtr = value; value->setParent(shared_from_this()); }
  DoublePtr Transpose::getDouble() const { return _doublePtr; }
  void Transpose::setDouble(const DoublePtr& value) { _doublePtr = value; value->setParent(shared_from_this()); }
  bool Transpose::hasNumber() const { return _hasNumber; }
  void Transpose::hasNumber(bool value) { _hasNumber = value; }
  int Transpose::number() const { return _number; }
  void Transpose::number(int value) { _number = value; }

  void Transpose::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
  }
  void Transpose::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
  }
  void Transpose::ostreamContents(pugi::xml_node& self) const
  {
    if(_diatonicPtr) {
      auto child = self.append_child("diatonic");
      _diatonicPtr->ostream(child);
    }
    if(_chromaticPtr) {
      auto child = self.append_child("chromatic");
      _chromaticPtr->ostream(child);
    }
    if(_octaveChangePtr) {
      auto child = self.append_child("octave-change");
      _octaveChangePtr->ostream(child);
    }
    if(_doublePtr) {
      auto child = self.append_child("double");
      _doublePtr->ostream(child);
    }
  }
  void Transpose::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "diatonic")==0) {
        auto diatonicPtr = std::make_shared<Diatonic>();
        diatonicPtr->istream(child);
        setDiatonic(diatonicPtr);
      }
      else if(strcmp(child.name(), "chromatic")==0) {
        auto chromaticPtr = std::make_shared<Chromatic>();
        chromaticPtr->istream(child);
        setChromatic(chromaticPtr);
      }
      else if(strcmp(child.name(), "octave-change")==0) {
        auto octaveChangePtr = std::make_shared<OctaveChange>();
        octaveChangePtr->istream(child);
        setOctaveChange(octaveChangePtr);
      }
      else if(strcmp(child.name(), "double")==0) {
        auto doublePtr = std::make_shared<Double>();
        doublePtr->istream(child);
        setDouble(doublePtr);
      }
    }
  }
}
