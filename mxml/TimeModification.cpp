#include "TimeModification.h"
#include <cstring>
#include "ActualNotes.h"
#include "NormalNotes.h"
#include "NormalType.h"
#include "NormalDot.h"

namespace mxml
{
  TimeModification::TimeModification() {}
  ActualNotesPtr TimeModification::getActualNotes() const { return _actualNotesPtr; }
  void TimeModification::setActualNotes(const ActualNotesPtr& value) { _actualNotesPtr = value; value->setParent(shared_from_this()); }
  NormalNotesPtr TimeModification::getNormalNotes() const { return _normalNotesPtr; }
  void TimeModification::setNormalNotes(const NormalNotesPtr& value) { _normalNotesPtr = value; value->setParent(shared_from_this()); }
  NormalTypePtr TimeModification::getNormalType() const { return _normalTypePtr; }
  void TimeModification::setNormalType(const NormalTypePtr& value) { _normalTypePtr = value; value->setParent(shared_from_this()); }
  const NormalDotSet& TimeModification::getNormalDotSet() const {  return _normalDotSet; }
  void TimeModification::removeNormalDot(const NormalDotPtr& value) { if(value) { auto i = std::find_if(_normalDotSet.begin(), _normalDotSet.end(), [&](const NormalDotPtr& item) { return item==value; }); if(i!=_normalDotSet.end()) _normalDotSet.erase(i); } } 
  void TimeModification::addNormalDot(const NormalDotPtr& value) { if(value) { _normalDotSet.push_back(value); value->setParent(shared_from_this()); } }
  void TimeModification::clearNormalDotSet() { _normalDotSet.clear(); }

  void TimeModification::ostreamContents(pugi::xml_node& self) const
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
  void TimeModification::istreamContents(const pugi::xml_node& self)
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
