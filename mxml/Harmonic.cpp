#include "Harmonic.h"
#include <cstring>
#include "Natural.h"
#include "Artificial.h"
#include "BasePitch.h"
#include "TouchingPitch.h"
#include "SoundingPitch.h"

namespace mxml
{
  Harmonic::Harmonic() {}
  NaturalPtr Harmonic::getNatural() const { return _naturalPtr; }
  void Harmonic::setNatural(const NaturalPtr& value) { _naturalPtr = value; value->setParent(shared_from_this()); }
  ArtificialPtr Harmonic::getArtificial() const { return _artificialPtr; }
  void Harmonic::setArtificial(const ArtificialPtr& value) { _artificialPtr = value; value->setParent(shared_from_this()); }
  BasePitchPtr Harmonic::getBasePitch() const { return _basePitchPtr; }
  void Harmonic::setBasePitch(const BasePitchPtr& value) { _basePitchPtr = value; value->setParent(shared_from_this()); }
  TouchingPitchPtr Harmonic::getTouchingPitch() const { return _touchingPitchPtr; }
  void Harmonic::setTouchingPitch(const TouchingPitchPtr& value) { _touchingPitchPtr = value; value->setParent(shared_from_this()); }
  SoundingPitchPtr Harmonic::getSoundingPitch() const { return _soundingPitchPtr; }
  void Harmonic::setSoundingPitch(const SoundingPitchPtr& value) { _soundingPitchPtr = value; value->setParent(shared_from_this()); }

  void Harmonic::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintObject::ostreamAttrs(self);
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
  }
  void Harmonic::istreamAttrs(const pugi::xml_node& self)
  {
    PrintObject::istreamAttrs(self);
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
  }
  void Harmonic::ostreamContents(pugi::xml_node& self) const
  {
    if(_naturalPtr) {
      auto child = self.append_child("natural");
      _naturalPtr->ostream(child);
    }
    else if(_artificialPtr) {
      auto child = self.append_child("artificial");
      _artificialPtr->ostream(child);
    }
    if(_basePitchPtr) {
      auto child = self.append_child("base-pitch");
      _basePitchPtr->ostream(child);
    }
    else if(_touchingPitchPtr) {
      auto child = self.append_child("touching-pitch");
      _touchingPitchPtr->ostream(child);
    }
    else if(_soundingPitchPtr) {
      auto child = self.append_child("sounding-pitch");
      _soundingPitchPtr->ostream(child);
    }
  }
  void Harmonic::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "natural")==0) {
        auto naturalPtr = std::make_shared<Natural>();
        naturalPtr->istream(child);
        setNatural(naturalPtr);
      }
      else if(strcmp(child.name(), "artificial")==0) {
        auto artificialPtr = std::make_shared<Artificial>();
        artificialPtr->istream(child);
        setArtificial(artificialPtr);
      }
      else if(strcmp(child.name(), "base-pitch")==0) {
        auto basePitchPtr = std::make_shared<BasePitch>();
        basePitchPtr->istream(child);
        setBasePitch(basePitchPtr);
      }
      else if(strcmp(child.name(), "touching-pitch")==0) {
        auto touchingPitchPtr = std::make_shared<TouchingPitch>();
        touchingPitchPtr->istream(child);
        setTouchingPitch(touchingPitchPtr);
      }
      else if(strcmp(child.name(), "sounding-pitch")==0) {
        auto soundingPitchPtr = std::make_shared<SoundingPitch>();
        soundingPitchPtr->istream(child);
        setSoundingPitch(soundingPitchPtr);
      }
    }
  }
}
