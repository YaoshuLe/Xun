#include "ScorePart.h"
#include <cstring>
#include "Identification.h"
#include "PartName.h"
#include "PartNameDisplay.h"
#include "PartAbbreviation.h"
#include "PartAbbreviationDisplay.h"
#include "Group.h"
#include "ScoreInstrument.h"
#include "MidiInfo.h"
#include "MidiDevice.h"
#include "MidiInstrument.h"

namespace mxml
{
  ScorePart::ScorePart() {}
  IdentificationPtr ScorePart::getIdentification() const { return _identificationPtr; }
  void ScorePart::setIdentification(const IdentificationPtr& value) { _identificationPtr = value; value->setParent(shared_from_this()); }
  PartNamePtr ScorePart::getPartName() const { return _partNamePtr; }
  void ScorePart::setPartName(const PartNamePtr& value) { _partNamePtr = value; value->setParent(shared_from_this()); }
  PartNameDisplayPtr ScorePart::getPartNameDisplay() const { return _partNameDisplayPtr; }
  void ScorePart::setPartNameDisplay(const PartNameDisplayPtr& value) { _partNameDisplayPtr = value; value->setParent(shared_from_this()); }
  PartAbbreviationPtr ScorePart::getPartAbbreviation() const { return _partAbbreviationPtr; }
  void ScorePart::setPartAbbreviation(const PartAbbreviationPtr& value) { _partAbbreviationPtr = value; value->setParent(shared_from_this()); }
  PartAbbreviationDisplayPtr ScorePart::getPartAbbreviationDisplay() const { return _partAbbreviationDisplayPtr; }
  void ScorePart::setPartAbbreviationDisplay(const PartAbbreviationDisplayPtr& value) { _partAbbreviationDisplayPtr = value; value->setParent(shared_from_this()); }
  const GroupSet& ScorePart::getGroupSet() const {  return _groupSet; }
  void ScorePart::removeGroup(const GroupPtr& value) { if(value) { auto i = std::find_if(_groupSet.begin(), _groupSet.end(), [&](const GroupPtr& item) { return item==value; }); if(i!=_groupSet.end()) _groupSet.erase(i); } } 
  void ScorePart::addGroup(const GroupPtr& value) { if(value) { _groupSet.push_back(value); value->setParent(shared_from_this()); } }
  void ScorePart::clearGroupSet() { _groupSet.clear(); }
  const ScoreInstrumentSet& ScorePart::getScoreInstrumentSet() const {  return _scoreInstrumentSet; }
  void ScorePart::removeScoreInstrument(const ScoreInstrumentPtr& value) { if(value) { auto i = std::find_if(_scoreInstrumentSet.begin(), _scoreInstrumentSet.end(), [&](const ScoreInstrumentPtr& item) { return item==value; }); if(i!=_scoreInstrumentSet.end()) _scoreInstrumentSet.erase(i); } } 
  void ScorePart::addScoreInstrument(const ScoreInstrumentPtr& value) { if(value) { _scoreInstrumentSet.push_back(value); value->setParent(shared_from_this()); } }
  void ScorePart::clearScoreInstrumentSet() { _scoreInstrumentSet.clear(); }
  const MidiInfoSet& ScorePart::getMidiInfoSet() const {  return _midiInfoSet; }
  void ScorePart::removeMidiInfo(const MidiInfoPtr& value) { if(value) { auto i = std::find_if(_midiInfoSet.begin(), _midiInfoSet.end(), [&](const MidiInfoPtr& item) { return item==value; }); if(i!=_midiInfoSet.end()) _midiInfoSet.erase(i); } } 
  void ScorePart::addMidiInfo(const MidiInfoPtr& value) { if(value) { _midiInfoSet.push_back(value); value->setParent(shared_from_this()); } }
  void ScorePart::clearMidiInfoSet() { _midiInfoSet.clear(); }
  bool ScorePart::hasId() const { return _hasId; }
  void ScorePart::hasId(bool value) { _hasId = value; }
  std::string ScorePart::id() const { return _id; }
  void ScorePart::id(std::string value) { _id = value; }

  void ScorePart::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasId) {
      self.append_attribute("id").set_value(_id.c_str());
    }
  }
  void ScorePart::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("id")) {
      _id = attr.as_string();
      _hasId = true;
    }
  }
  void ScorePart::ostreamContents(pugi::xml_node& self) const
  {
    if(_identificationPtr) {
      auto child = self.append_child("identification");
      _identificationPtr->ostream(child);
    }
    if(_partNamePtr) {
      auto child = self.append_child("part-name");
      _partNamePtr->ostream(child);
    }
    if(_partNameDisplayPtr) {
      auto child = self.append_child("part-name-display");
      _partNameDisplayPtr->ostream(child);
    }
    if(_partAbbreviationPtr) {
      auto child = self.append_child("part-abbreviation");
      _partAbbreviationPtr->ostream(child);
    }
    if(_partAbbreviationDisplayPtr) {
      auto child = self.append_child("part-abbreviation-display");
      _partAbbreviationDisplayPtr->ostream(child);
    }
    for(auto item : _groupSet) {
      auto child = self.append_child("group");
      item->ostream(child);
    }
    for(auto item : _scoreInstrumentSet) {
      auto child = self.append_child("score-instrument");
      item->ostream(child);
    }
    for(auto item : _midiInfoSet) {
      item->ostream(self);
    }
  }
  void ScorePart::istreamContents(const pugi::xml_node& self)
  {
    MidiInfoPtr midiInfoPtr;
    for(auto child: self.children()) {
      if(strcmp(child.name(), "identification")==0) {
        auto identificationPtr = std::make_shared<Identification>();
        identificationPtr->istream(child);
        setIdentification(identificationPtr);
      }
      else if(strcmp(child.name(), "part-name")==0) {
        auto partNamePtr = std::make_shared<PartName>();
        partNamePtr->istream(child);
        setPartName(partNamePtr);
      }
      else if(strcmp(child.name(), "part-name-display")==0) {
        auto partNameDisplayPtr = std::make_shared<PartNameDisplay>();
        partNameDisplayPtr->istream(child);
        setPartNameDisplay(partNameDisplayPtr);
      }
      else if(strcmp(child.name(), "part-abbreviation")==0) {
        auto partAbbreviationPtr = std::make_shared<PartAbbreviation>();
        partAbbreviationPtr->istream(child);
        setPartAbbreviation(partAbbreviationPtr);
      }
      else if(strcmp(child.name(), "part-abbreviation-display")==0) {
        auto partAbbreviationDisplayPtr = std::make_shared<PartAbbreviationDisplay>();
        partAbbreviationDisplayPtr->istream(child);
        setPartAbbreviationDisplay(partAbbreviationDisplayPtr);
      }
      else if(strcmp(child.name(), "group")==0) {
        auto groupPtr = std::make_shared<Group>();
        groupPtr->istream(child);
        addGroup(groupPtr);
      }
      else if(strcmp(child.name(), "score-instrument")==0) {
        auto scoreInstrumentPtr = std::make_shared<ScoreInstrument>();
        scoreInstrumentPtr->istream(child);
        addScoreInstrument(scoreInstrumentPtr);
      }
      else if(strcmp(child.name(), "midi-device")==0) {
        auto midiDevicePtr = std::make_shared<MidiDevice>();
        midiDevicePtr->istream(child);
        midiInfoPtr = std::make_shared<MidiInfo>();
        midiInfoPtr->setMidiDevice(midiDevicePtr);
        addMidiInfo(midiInfoPtr);
      }
      else if(strcmp(child.name(), "midi-instrument")==0) {
        if(midiInfoPtr) {
          auto midiInstrumentPtr = std::make_shared<MidiInstrument>();
          midiInstrumentPtr->istream(child);
          midiInfoPtr->setMidiInstrument(midiInstrumentPtr);
        }  
      }
    }
  }
}
