#include "Percussion.h"
#include <cstring>
#include "Glass.h"
#include "Metal.h"
#include "Wood.h"
#include "Pitched.h"
#include "Membrane.h"
#include "Effect.h"
#include "Timpani.h"
#include "Beater.h"
#include "Stick.h"
#include "StickLocation.h"
#include "OtherPercussion.h"

namespace mxml
{
  Percussion::Percussion() {}
  GlassPtr Percussion::getGlass() const { return _glassPtr; }
  void Percussion::setGlass(const GlassPtr& value) { _glassPtr = value; value->setParent(shared_from_this()); }
  MetalPtr Percussion::getMetal() const { return _metalPtr; }
  void Percussion::setMetal(const MetalPtr& value) { _metalPtr = value; value->setParent(shared_from_this()); }
  WoodPtr Percussion::getWood() const { return _woodPtr; }
  void Percussion::setWood(const WoodPtr& value) { _woodPtr = value; value->setParent(shared_from_this()); }
  PitchedPtr Percussion::getPitched() const { return _pitchedPtr; }
  void Percussion::setPitched(const PitchedPtr& value) { _pitchedPtr = value; value->setParent(shared_from_this()); }
  MembranePtr Percussion::getMembrane() const { return _membranePtr; }
  void Percussion::setMembrane(const MembranePtr& value) { _membranePtr = value; value->setParent(shared_from_this()); }
  EffectPtr Percussion::getEffect() const { return _effectPtr; }
  void Percussion::setEffect(const EffectPtr& value) { _effectPtr = value; value->setParent(shared_from_this()); }
  TimpaniPtr Percussion::getTimpani() const { return _timpaniPtr; }
  void Percussion::setTimpani(const TimpaniPtr& value) { _timpaniPtr = value; value->setParent(shared_from_this()); }
  BeaterPtr Percussion::getBeater() const { return _beaterPtr; }
  void Percussion::setBeater(const BeaterPtr& value) { _beaterPtr = value; value->setParent(shared_from_this()); }
  StickPtr Percussion::getStick() const { return _stickPtr; }
  void Percussion::setStick(const StickPtr& value) { _stickPtr = value; value->setParent(shared_from_this()); }
  StickLocationPtr Percussion::getStickLocation() const { return _stickLocationPtr; }
  void Percussion::setStickLocation(const StickLocationPtr& value) { _stickLocationPtr = value; value->setParent(shared_from_this()); }
  OtherPercussionPtr Percussion::getOtherPercussion() const { return _otherPercussionPtr; }
  void Percussion::setOtherPercussion(const OtherPercussionPtr& value) { _otherPercussionPtr = value; value->setParent(shared_from_this()); }

  void Percussion::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyleAlign::ostreamAttrs(self);
    Enclosure::ostreamAttrs(self);
  }
  void Percussion::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyleAlign::istreamAttrs(self);
    Enclosure::istreamAttrs(self);
  }
  void Percussion::ostreamContents(pugi::xml_node& self) const
  {
    if(_glassPtr) {
      auto child = self.append_child("glass");
      _glassPtr->ostream(child);
    }
    else if(_metalPtr) {
      auto child = self.append_child("metal");
      _metalPtr->ostream(child);
    }
    else if(_woodPtr) {
      auto child = self.append_child("wood");
      _woodPtr->ostream(child);
    }
    else if(_pitchedPtr) {
      auto child = self.append_child("pitched");
      _pitchedPtr->ostream(child);
    }
    else if(_membranePtr) {
      auto child = self.append_child("membrane");
      _membranePtr->ostream(child);
    }
    else if(_effectPtr) {
      auto child = self.append_child("effect");
      _effectPtr->ostream(child);
    }
    else if(_timpaniPtr) {
      auto child = self.append_child("timpani");
      _timpaniPtr->ostream(child);
    }
    else if(_beaterPtr) {
      auto child = self.append_child("beater");
      _beaterPtr->ostream(child);
    }
    else if(_stickPtr) {
      auto child = self.append_child("stick");
      _stickPtr->ostream(child);
    }
    else if(_stickLocationPtr) {
      auto child = self.append_child("stick-location");
      _stickLocationPtr->ostream(child);
    }
    else if(_otherPercussionPtr) {
      auto child = self.append_child("other-percussion");
      _otherPercussionPtr->ostream(child);
    }
  }
  void Percussion::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "glass")==0) {
        auto glassPtr = std::make_shared<Glass>();
        glassPtr->istream(child);
        setGlass(glassPtr);
      }
      else if(strcmp(child.name(), "metal")==0) {
        auto metalPtr = std::make_shared<Metal>();
        metalPtr->istream(child);
        setMetal(metalPtr);
      }
      else if(strcmp(child.name(), "wood")==0) {
        auto woodPtr = std::make_shared<Wood>();
        woodPtr->istream(child);
        setWood(woodPtr);
      }
      else if(strcmp(child.name(), "pitched")==0) {
        auto pitchedPtr = std::make_shared<Pitched>();
        pitchedPtr->istream(child);
        setPitched(pitchedPtr);
      }
      else if(strcmp(child.name(), "membrane")==0) {
        auto membranePtr = std::make_shared<Membrane>();
        membranePtr->istream(child);
        setMembrane(membranePtr);
      }
      else if(strcmp(child.name(), "effect")==0) {
        auto effectPtr = std::make_shared<Effect>();
        effectPtr->istream(child);
        setEffect(effectPtr);
      }
      else if(strcmp(child.name(), "timpani")==0) {
        auto timpaniPtr = std::make_shared<Timpani>();
        timpaniPtr->istream(child);
        setTimpani(timpaniPtr);
      }
      else if(strcmp(child.name(), "beater")==0) {
        auto beaterPtr = std::make_shared<Beater>();
        beaterPtr->istream(child);
        setBeater(beaterPtr);
      }
      else if(strcmp(child.name(), "stick")==0) {
        auto stickPtr = std::make_shared<Stick>();
        stickPtr->istream(child);
        setStick(stickPtr);
      }
      else if(strcmp(child.name(), "stick-location")==0) {
        auto stickLocationPtr = std::make_shared<StickLocation>();
        stickLocationPtr->istream(child);
        setStickLocation(stickLocationPtr);
      }
      else if(strcmp(child.name(), "other-percussion")==0) {
        auto otherPercussionPtr = std::make_shared<OtherPercussion>();
        otherPercussionPtr->istream(child);
        setOtherPercussion(otherPercussionPtr);
      }
    }
  }
}
