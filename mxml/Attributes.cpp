#include "Attributes.h"
#include <cstring>
#include "Footnote.h"
#include "Level.h"
#include "Divisions.h"
#include "Key.h"
#include "Time.h"
#include "Staves.h"
#include "PartSymbol.h"
#include "Instruments.h"
#include "Clef.h"
#include "StaffDetails.h"
#include "Transpose.h"
#include "MeasureStyle.h"

namespace mxml
{
  Attributes::Attributes() {}
  FootnotePtr Attributes::getFootnote() const { return _footnotePtr; }
  void Attributes::setFootnote(const FootnotePtr& value) { _footnotePtr = value; value->setParent(shared_from_this()); }
  LevelPtr Attributes::getLevel() const { return _levelPtr; }
  void Attributes::setLevel(const LevelPtr& value) { _levelPtr = value; value->setParent(shared_from_this()); }
  DivisionsPtr Attributes::getDivisions() const { return _divisionsPtr; }
  void Attributes::setDivisions(const DivisionsPtr& value) { _divisionsPtr = value; value->setParent(shared_from_this()); }
  const KeySet& Attributes::getKeySet() const {  return _keySet; }
  void Attributes::removeKey(const KeyPtr& value) { if(value) { auto i = std::find_if(_keySet.begin(), _keySet.end(), [&](const KeyPtr& item) { return item==value; }); if(i!=_keySet.end()) _keySet.erase(i); } } 
  void Attributes::addKey(const KeyPtr& value) { if(value) { _keySet.push_back(value); value->setParent(shared_from_this()); } }
  void Attributes::clearKeySet() { _keySet.clear(); }
  const TimeSet& Attributes::getTimeSet() const {  return _timeSet; }
  void Attributes::removeTime(const TimePtr& value) { if(value) { auto i = std::find_if(_timeSet.begin(), _timeSet.end(), [&](const TimePtr& item) { return item==value; }); if(i!=_timeSet.end()) _timeSet.erase(i); } } 
  void Attributes::addTime(const TimePtr& value) { if(value) { _timeSet.push_back(value); value->setParent(shared_from_this()); } }
  void Attributes::clearTimeSet() { _timeSet.clear(); }
  StavesPtr Attributes::getStaves() const { return _stavesPtr; }
  void Attributes::setStaves(const StavesPtr& value) { _stavesPtr = value; value->setParent(shared_from_this()); }
  PartSymbolPtr Attributes::getPartSymbol() const { return _partSymbolPtr; }
  void Attributes::setPartSymbol(const PartSymbolPtr& value) { _partSymbolPtr = value; value->setParent(shared_from_this()); }
  InstrumentsPtr Attributes::getInstruments() const { return _instrumentsPtr; }
  void Attributes::setInstruments(const InstrumentsPtr& value) { _instrumentsPtr = value; value->setParent(shared_from_this()); }
  const ClefSet& Attributes::getClefSet() const {  return _clefSet; }
  void Attributes::removeClef(const ClefPtr& value) { if(value) { auto i = std::find_if(_clefSet.begin(), _clefSet.end(), [&](const ClefPtr& item) { return item==value; }); if(i!=_clefSet.end()) _clefSet.erase(i); } } 
  void Attributes::addClef(const ClefPtr& value) { if(value) { _clefSet.push_back(value); value->setParent(shared_from_this()); } }
  void Attributes::clearClefSet() { _clefSet.clear(); }
  const StaffDetailsSet& Attributes::getStaffDetailsSet() const {  return _staffDetailsSet; }
  void Attributes::removeStaffDetails(const StaffDetailsPtr& value) { if(value) { auto i = std::find_if(_staffDetailsSet.begin(), _staffDetailsSet.end(), [&](const StaffDetailsPtr& item) { return item==value; }); if(i!=_staffDetailsSet.end()) _staffDetailsSet.erase(i); } } 
  void Attributes::addStaffDetails(const StaffDetailsPtr& value) { if(value) { _staffDetailsSet.push_back(value); value->setParent(shared_from_this()); } }
  void Attributes::clearStaffDetailsSet() { _staffDetailsSet.clear(); }
  const TransposeSet& Attributes::getTransposeSet() const {  return _transposeSet; }
  void Attributes::removeTranspose(const TransposePtr& value) { if(value) { auto i = std::find_if(_transposeSet.begin(), _transposeSet.end(), [&](const TransposePtr& item) { return item==value; }); if(i!=_transposeSet.end()) _transposeSet.erase(i); } } 
  void Attributes::addTranspose(const TransposePtr& value) { if(value) { _transposeSet.push_back(value); value->setParent(shared_from_this()); } }
  void Attributes::clearTransposeSet() { _transposeSet.clear(); }
  const MeasureStyleSet& Attributes::getMeasureStyleSet() const {  return _measureStyleSet; }
  void Attributes::removeMeasureStyle(const MeasureStylePtr& value) { if(value) { auto i = std::find_if(_measureStyleSet.begin(), _measureStyleSet.end(), [&](const MeasureStylePtr& item) { return item==value; }); if(i!=_measureStyleSet.end()) _measureStyleSet.erase(i); } } 
  void Attributes::addMeasureStyle(const MeasureStylePtr& value) { if(value) { _measureStyleSet.push_back(value); value->setParent(shared_from_this()); } }
  void Attributes::clearMeasureStyleSet() { _measureStyleSet.clear(); }

  void Attributes::ostreamContents(pugi::xml_node& self) const
  {
    if(_footnotePtr) {
      auto child = self.append_child("footnote");
      _footnotePtr->ostream(child);
    }
    if(_levelPtr) {
      auto child = self.append_child("level");
      _levelPtr->ostream(child);
    }
    if(_divisionsPtr) {
      auto child = self.append_child("divisions");
      _divisionsPtr->ostream(child);
    }
    for(auto item : _keySet) {
      auto child = self.append_child("key");
      item->ostream(child);
    }
    for(auto item : _timeSet) {
      auto child = self.append_child("time");
      item->ostream(child);
    }
    if(_stavesPtr) {
      auto child = self.append_child("staves");
      _stavesPtr->ostream(child);
    }
    if(_partSymbolPtr) {
      auto child = self.append_child("part-symbol");
      _partSymbolPtr->ostream(child);
    }
    if(_instrumentsPtr) {
      auto child = self.append_child("instruments");
      _instrumentsPtr->ostream(child);
    }
    for(auto item : _clefSet) {
      auto child = self.append_child("clef");
      item->ostream(child);
    }
    for(auto item : _staffDetailsSet) {
      auto child = self.append_child("staff-details");
      item->ostream(child);
    }
    for(auto item : _transposeSet) {
      auto child = self.append_child("transpose");
      item->ostream(child);
    }
    for(auto item : _measureStyleSet) {
      auto child = self.append_child("measure-style");
      item->ostream(child);
    }
  }
  void Attributes::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "footnote")==0) {
        auto footnotePtr = std::make_shared<Footnote>();
        footnotePtr->istream(child);
        setFootnote(footnotePtr);
      }
      else if(strcmp(child.name(), "level")==0) {
        auto levelPtr = std::make_shared<Level>();
        levelPtr->istream(child);
        setLevel(levelPtr);
      }
      else if(strcmp(child.name(), "divisions")==0) {
        auto divisionsPtr = std::make_shared<Divisions>();
        divisionsPtr->istream(child);
        setDivisions(divisionsPtr);
      }
      else if(strcmp(child.name(), "key")==0) {
        auto keyPtr = std::make_shared<Key>();
        keyPtr->istream(child);
        addKey(keyPtr);
      }
      else if(strcmp(child.name(), "time")==0) {
        auto timePtr = std::make_shared<Time>();
        timePtr->istream(child);
        addTime(timePtr);
      }
      else if(strcmp(child.name(), "staves")==0) {
        auto stavesPtr = std::make_shared<Staves>();
        stavesPtr->istream(child);
        setStaves(stavesPtr);
      }
      else if(strcmp(child.name(), "part-symbol")==0) {
        auto partSymbolPtr = std::make_shared<PartSymbol>();
        partSymbolPtr->istream(child);
        setPartSymbol(partSymbolPtr);
      }
      else if(strcmp(child.name(), "instruments")==0) {
        auto instrumentsPtr = std::make_shared<Instruments>();
        instrumentsPtr->istream(child);
        setInstruments(instrumentsPtr);
      }
      else if(strcmp(child.name(), "clef")==0) {
        auto clefPtr = std::make_shared<Clef>();
        clefPtr->istream(child);
        addClef(clefPtr);
      }
      else if(strcmp(child.name(), "staff-details")==0) {
        auto staffDetailsPtr = std::make_shared<StaffDetails>();
        staffDetailsPtr->istream(child);
        addStaffDetails(staffDetailsPtr);
      }
      else if(strcmp(child.name(), "transpose")==0) {
        auto transposePtr = std::make_shared<Transpose>();
        transposePtr->istream(child);
        addTranspose(transposePtr);
      }
      else if(strcmp(child.name(), "measure-style")==0) {
        auto measureStylePtr = std::make_shared<MeasureStyle>();
        measureStylePtr->istream(child);
        addMeasureStyle(measureStylePtr);
      }
    }
  }
}
