#include "Interchangeable.h"
#include <cstring>
#include "TimeRelation.h"
#include "TimeSignature.h"
#include "Beats.h"
#include "BeatType.h"

namespace mxml
{
  Interchangeable::Interchangeable() {}
  TimeRelationPtr Interchangeable::getTimeRelation() const { return _timeRelationPtr; }
  void Interchangeable::setTimeRelation(const TimeRelationPtr& value) { _timeRelationPtr = value; value->setParent(shared_from_this()); }
  const TimeSignatureSet& Interchangeable::getTimeSignatureSet() const {  return _timeSignatureSet; }
  void Interchangeable::removeTimeSignature(const TimeSignaturePtr& value) { if(value) { auto i = std::find_if(_timeSignatureSet.begin(), _timeSignatureSet.end(), [&](const TimeSignaturePtr& item) { return item==value; }); if(i!=_timeSignatureSet.end()) _timeSignatureSet.erase(i); } } 
  void Interchangeable::addTimeSignature(const TimeSignaturePtr& value) { if(value) { _timeSignatureSet.push_back(value); value->setParent(shared_from_this()); } }
  void Interchangeable::clearTimeSignatureSet() { _timeSignatureSet.clear(); }
  bool Interchangeable::hasSymbol() const { return _hasSymbol; }
  void Interchangeable::hasSymbol(bool value) { _hasSymbol = value; }
  TimeSymbolEnum Interchangeable::symbol() const { return _symbol; }
  void Interchangeable::symbol(TimeSymbolEnum value) { _symbol = value; }
  bool Interchangeable::hasSeparator() const { return _hasSeparator; }
  void Interchangeable::hasSeparator(bool value) { _hasSeparator = value; }
  TimeSeparatorEnum Interchangeable::separator() const { return _separator; }
  void Interchangeable::separator(TimeSeparatorEnum value) { _separator = value; }

  void Interchangeable::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasSymbol) {
      self.append_attribute("symbol").set_value(_symbol.operator const char *());
    }
    if(_hasSeparator) {
      self.append_attribute("separator").set_value(_separator.operator const char *());
    }
  }
  void Interchangeable::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("symbol")) {
      _symbol = TimeSymbolEnum(attr.as_string());
      _hasSymbol = true;
    }
    if(auto attr = self.attribute("separator")) {
      _separator = TimeSeparatorEnum(attr.as_string());
      _hasSeparator = true;
    }
  }
  void Interchangeable::ostreamContents(pugi::xml_node& self) const
  {
    if(_timeRelationPtr) {
      auto child = self.append_child("time-relation");
      _timeRelationPtr->ostream(child);
    }
    for(auto item : _timeSignatureSet) {
      item->ostream(self);
    }
  }
  void Interchangeable::istreamContents(const pugi::xml_node& self)
  {
    TimeSignaturePtr timeSignaturePtr;
    for(auto child: self.children()) {
      if(strcmp(child.name(), "time-relation")==0) {
        auto timeRelationPtr = std::make_shared<TimeRelation>();
        timeRelationPtr->istream(child);
        setTimeRelation(timeRelationPtr);
      }
      else if(strcmp(child.name(), "beats")==0) {
        auto beatsPtr = std::make_shared<Beats>();
        beatsPtr->istream(child);
        timeSignaturePtr = std::make_shared<TimeSignature>();
        timeSignaturePtr->setBeats(beatsPtr);
        addTimeSignature(timeSignaturePtr);
      }
      else if(strcmp(child.name(), "beat-type")==0) {
        if(timeSignaturePtr) {
          auto beatTypePtr = std::make_shared<BeatType>();
          beatTypePtr->istream(child);
          timeSignaturePtr->setBeatType(beatTypePtr);
        }
      }
    }
  }
}
