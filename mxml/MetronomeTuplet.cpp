#include "MetronomeTuplet.h"
#include <cstring>
#include "ActualNotes.h"
#include "NormalNotes.h"
#include "NormalType.h"
#include "NormalDot.h"

namespace mxml
{
  MetronomeTuplet::MetronomeTuplet() {}
  ActualNotesPtr MetronomeTuplet::getActualNotes() const { return _actualNotesPtr; }
  void MetronomeTuplet::setActualNotes(const ActualNotesPtr& value) { _actualNotesPtr = value; value->setParent(shared_from_this()); }
  NormalNotesPtr MetronomeTuplet::getNormalNotes() const { return _normalNotesPtr; }
  void MetronomeTuplet::setNormalNotes(const NormalNotesPtr& value) { _normalNotesPtr = value; value->setParent(shared_from_this()); }
  NormalTypePtr MetronomeTuplet::getNormalType() const { return _normalTypePtr; }
  void MetronomeTuplet::setNormalType(const NormalTypePtr& value) { _normalTypePtr = value; value->setParent(shared_from_this()); }
  const NormalDotSet& MetronomeTuplet::getNormalDotSet() const {  return _normalDotSet; }
  void MetronomeTuplet::removeNormalDot(const NormalDotPtr& value) { if(value) { auto i = std::find_if(_normalDotSet.begin(), _normalDotSet.end(), [&](const NormalDotPtr& item) { return item==value; }); if(i!=_normalDotSet.end()) _normalDotSet.erase(i); } } 
  void MetronomeTuplet::addNormalDot(const NormalDotPtr& value) { if(value) { _normalDotSet.push_back(value); value->setParent(shared_from_this()); } }
  void MetronomeTuplet::clearNormalDotSet() { _normalDotSet.clear(); }
  bool MetronomeTuplet::hasType() const { return _hasType; }
  void MetronomeTuplet::hasType(bool value) { _hasType = value; }
  StartStopEnum MetronomeTuplet::type() const { return _type; }
  void MetronomeTuplet::type(StartStopEnum value) { _type = value; }
  bool MetronomeTuplet::hasBracket() const { return _hasBracket; }
  void MetronomeTuplet::hasBracket(bool value) { _hasBracket = value; }
  YesNoEnum MetronomeTuplet::bracket() const { return _bracket; }
  void MetronomeTuplet::bracket(YesNoEnum value) { _bracket = value; }
  bool MetronomeTuplet::hasShowNumber() const { return _hasShowNumber; }
  void MetronomeTuplet::hasShowNumber(bool value) { _hasShowNumber = value; }
  ShowTupletEnum MetronomeTuplet::showNumber() const { return _showNumber; }
  void MetronomeTuplet::showNumber(ShowTupletEnum value) { _showNumber = value; }

  void MetronomeTuplet::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasBracket) {
      self.append_attribute("bracket").set_value(_bracket.operator const char *());
    }
    if(_hasShowNumber) {
      self.append_attribute("show-number").set_value(_showNumber.operator const char *());
    }
  }
  void MetronomeTuplet::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = StartStopEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("bracket")) {
      _bracket = YesNoEnum(attr.as_string());
      _hasBracket = true;
    }
    if(auto attr = self.attribute("show-number")) {
      _showNumber = ShowTupletEnum(attr.as_string());
      _hasShowNumber = true;
    }
  }
  void MetronomeTuplet::ostreamContents(pugi::xml_node& self) const
  {
    if(_actualNotesPtr) {
      auto child = self.append_child("actual-notes");
      _actualNotesPtr->ostream(child);
    }
    if(_normalNotesPtr) {
      auto child = self.append_child("normal-notes");
      _normalNotesPtr->ostream(child);
    }
    if(_normalTypePtr) {
      auto child = self.append_child("normal-type");
      _normalTypePtr->ostream(child);
    }
    for(auto item : _normalDotSet) {
      auto child = self.append_child("normal-dot");
      item->ostream(child);
    }
  }
  void MetronomeTuplet::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "actual-notes")==0) {
        auto actualNotesPtr = std::make_shared<ActualNotes>();
        actualNotesPtr->istream(child);
        setActualNotes(actualNotesPtr);
      }
      else if(strcmp(child.name(), "normal-notes")==0) {
        auto normalNotesPtr = std::make_shared<NormalNotes>();
        normalNotesPtr->istream(child);
        setNormalNotes(normalNotesPtr);
      }
      else if(strcmp(child.name(), "normal-type")==0) {
        auto normalTypePtr = std::make_shared<NormalType>();
        normalTypePtr->istream(child);
        setNormalType(normalTypePtr);
      }
      else if(strcmp(child.name(), "normal-dot")==0) {
        auto normalDotPtr = std::make_shared<NormalDot>();
        normalDotPtr->istream(child);
        addNormalDot(normalDotPtr);
      }
    }
  }
}
