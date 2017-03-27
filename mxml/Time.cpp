#include "Time.h"
#include <cstring>
#include "TimeSignature.h"
#include "Beats.h"
#include "BeatType.h"
#include "Interchangeable.h"
#include "SenzaMisura.h"

namespace mxml
{
  Time::Time() {}
  const TimeSignatureSet& Time::getTimeSignatureSet() const {  return _timeSignatureSet; }
  void Time::removeTimeSignature(const TimeSignaturePtr& value) { if(value) { auto i = std::find_if(_timeSignatureSet.begin(), _timeSignatureSet.end(), [&](const TimeSignaturePtr& item) { return item==value; }); if(i!=_timeSignatureSet.end()) _timeSignatureSet.erase(i); } } 
  void Time::addTimeSignature(const TimeSignaturePtr& value) { if(value) { _timeSignatureSet.push_back(value); value->setParent(shared_from_this()); } }
  void Time::clearTimeSignatureSet() { _timeSignatureSet.clear(); }
  InterchangeablePtr Time::getInterchangeable() const { return _interchangeablePtr; }
  void Time::setInterchangeable(const InterchangeablePtr& value) { _interchangeablePtr = value; value->setParent(shared_from_this()); }
  SenzaMisuraPtr Time::getSenzaMisura() const { return _senzaMisuraPtr; }
  void Time::setSenzaMisura(const SenzaMisuraPtr& value) { _senzaMisuraPtr = value; value->setParent(shared_from_this()); }
  bool Time::hasNumber() const { return _hasNumber; }
  void Time::hasNumber(bool value) { _hasNumber = value; }
  int Time::number() const { return _number; }
  void Time::number(int value) { _number = value; }
  bool Time::hasSymbol() const { return _hasSymbol; }
  void Time::hasSymbol(bool value) { _hasSymbol = value; }
  TimeSymbolEnum Time::symbol() const { return _symbol; }
  void Time::symbol(TimeSymbolEnum value) { _symbol = value; }
  bool Time::hasSeparator() const { return _hasSeparator; }
  void Time::hasSeparator(bool value) { _hasSeparator = value; }
  TimeSeparatorEnum Time::separator() const { return _separator; }
  void Time::separator(TimeSeparatorEnum value) { _separator = value; }

  void Time::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyleAlign::ostreamAttrs(self);
    PrintObject::ostreamAttrs(self);
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
    if(_hasSymbol) {
      self.append_attribute("symbol").set_value(_symbol.operator const char *());
    }
    if(_hasSeparator) {
      self.append_attribute("separator").set_value(_separator.operator const char *());
    }
  }
  void Time::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyleAlign::istreamAttrs(self);
    PrintObject::istreamAttrs(self);
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("symbol")) {
      _symbol = TimeSymbolEnum(attr.as_string());
      _hasSymbol = true;
    }
    if(auto attr = self.attribute("separator")) {
      _separator = TimeSeparatorEnum(attr.as_string());
      _hasSeparator = true;
    }
  }
  void Time::ostreamContents(pugi::xml_node& self) const
  {
    if(_senzaMisuraPtr) {
      auto child = self.append_child("senza-misura");
      _senzaMisuraPtr->ostream(child);
    }
    else {
      for(auto item : _timeSignatureSet) {
        item->ostream(self);
      }
      if(_interchangeablePtr) {
        auto child = self.append_child("interchangeable");
        _interchangeablePtr->ostream(child);
      }
    }
  }
  void Time::istreamContents(const pugi::xml_node& self)
  {
    if(self.children().begin()==self.children().end()) return;
    auto begin = *(self.children().begin());
    if((strcmp(begin.name(), "senza-misura")==0)) {
      for(auto child: self.children()) {
        if(strcmp(child.name(), "senza-misura")==0) {
          auto senzaMisuraPtr = std::make_shared<SenzaMisura>();
          senzaMisuraPtr->istream(child);
          setSenzaMisura(senzaMisuraPtr);
        }
      }
    }
    else {
      TimeSignaturePtr timeSignaturePtr;
      for(auto child: self.children()) {
        if(strcmp(child.name(), "beats")==0) {
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
        else if(strcmp(child.name(), "interchangeable")==0) {
          auto interchangeablePtr = std::make_shared<Interchangeable>();
          interchangeablePtr->istream(child);
          setInterchangeable(interchangeablePtr);
        }
      }   
    }
  }
}
