#include "ScoreInstrument.h"
#include <cstring>
#include "InstrumentName.h"
#include "InstrumentAbbreviation.h"
#include "InstrumentSound.h"
#include "Solo.h"
#include "Ensemble.h"
#include "VirtualInstrument.h"

namespace mxml
{
  ScoreInstrument::ScoreInstrument() {}
  InstrumentNamePtr ScoreInstrument::getInstrumentName() const { return _instrumentNamePtr; }
  void ScoreInstrument::setInstrumentName(const InstrumentNamePtr& value) { _instrumentNamePtr = value; value->setParent(shared_from_this()); }
  InstrumentAbbreviationPtr ScoreInstrument::getInstrumentAbbreviation() const { return _instrumentAbbreviationPtr; }
  void ScoreInstrument::setInstrumentAbbreviation(const InstrumentAbbreviationPtr& value) { _instrumentAbbreviationPtr = value; value->setParent(shared_from_this()); }
  InstrumentSoundPtr ScoreInstrument::getInstrumentSound() const { return _instrumentSoundPtr; }
  void ScoreInstrument::setInstrumentSound(const InstrumentSoundPtr& value) { _instrumentSoundPtr = value; value->setParent(shared_from_this()); }
  SoloPtr ScoreInstrument::getSolo() const { return _soloPtr; }
  void ScoreInstrument::setSolo(const SoloPtr& value) { _soloPtr = value; value->setParent(shared_from_this()); }
  EnsemblePtr ScoreInstrument::getEnsemble() const { return _ensemblePtr; }
  void ScoreInstrument::setEnsemble(const EnsemblePtr& value) { _ensemblePtr = value; value->setParent(shared_from_this()); }
  VirtualInstrumentPtr ScoreInstrument::getVirtualInstrument() const { return _virtualInstrumentPtr; }
  void ScoreInstrument::setVirtualInstrument(const VirtualInstrumentPtr& value) { _virtualInstrumentPtr = value; value->setParent(shared_from_this()); }
  bool ScoreInstrument::hasId() const { return _hasId; }
  void ScoreInstrument::hasId(bool value) { _hasId = value; }
  std::string ScoreInstrument::id() const { return _id; }
  void ScoreInstrument::id(std::string value) { _id = value; }

  void ScoreInstrument::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasId) {
      self.append_attribute("id").set_value(_id.c_str());
    }
  }
  void ScoreInstrument::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("id")) {
      _id = attr.as_string();
      _hasId = true;
    }
  }
  void ScoreInstrument::ostreamContents(pugi::xml_node& self) const
  {
    if(_instrumentNamePtr) {
      auto child = self.append_child("instrument-name");
      _instrumentNamePtr->ostream(child);
    }
    if(_instrumentAbbreviationPtr) {
      auto child = self.append_child("instrument-abbreviation");
      _instrumentAbbreviationPtr->ostream(child);
    }
    if(_instrumentSoundPtr) {
      auto child = self.append_child("instrument-sound");
      _instrumentSoundPtr->ostream(child);
    }
    if(_soloPtr) {
      auto child = self.append_child("solo");
      _soloPtr->ostream(child);
    }
    else if(_ensemblePtr) {
      auto child = self.append_child("ensemble");
      _ensemblePtr->ostream(child);
    }
    if(_virtualInstrumentPtr) {
      auto child = self.append_child("virtual-instrument");
      _virtualInstrumentPtr->ostream(child);
    }
  }
  void ScoreInstrument::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "instrument-name")==0) {
        auto instrumentNamePtr = std::make_shared<InstrumentName>();
        instrumentNamePtr->istream(child);
        setInstrumentName(instrumentNamePtr);
      }
      else if(strcmp(child.name(), "instrument-abbreviation")==0) {
        auto instrumentAbbreviationPtr = std::make_shared<InstrumentAbbreviation>();
        instrumentAbbreviationPtr->istream(child);
        setInstrumentAbbreviation(instrumentAbbreviationPtr);
      }
      else if(strcmp(child.name(), "instrument-sound")==0) {
        auto instrumentSoundPtr = std::make_shared<InstrumentSound>();
        instrumentSoundPtr->istream(child);
        setInstrumentSound(instrumentSoundPtr);
      }
      else if(strcmp(child.name(), "solo")==0) {
        auto soloPtr = std::make_shared<Solo>();
        soloPtr->istream(child);
        setSolo(soloPtr);
      }
      else if(strcmp(child.name(), "ensemble")==0) {
        auto ensemblePtr = std::make_shared<Ensemble>();
        ensemblePtr->istream(child);
        setEnsemble(ensemblePtr);
      }
      else if(strcmp(child.name(), "virtual-instrument")==0) {
        auto virtualInstrumentPtr = std::make_shared<VirtualInstrument>();
        virtualInstrumentPtr->istream(child);
        setVirtualInstrument(virtualInstrumentPtr);
      }
    }
  }
}
