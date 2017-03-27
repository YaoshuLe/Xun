#include "ScorePartwise.h"
#include <cstring>
#include "Work.h"
#include "MovementNumber.h"
#include "MovementTitle.h"
#include "Identification.h"
#include "Defaults.h"
#include "Credit.h"
#include "PartGroup.h"
#include "ScorePart.h"
#include "Part.h"

namespace mxml
{
  ScorePartwise::ScorePartwise() {}
  WorkPtr ScorePartwise::getWork() const { return _workPtr; }
  void ScorePartwise::setWork(const WorkPtr& value) { _workPtr = value; value->setParent(shared_from_this()); }
  MovementNumberPtr ScorePartwise::getMovementNumber() const { return _movementNumberPtr; }
  void ScorePartwise::setMovementNumber(const MovementNumberPtr& value) { _movementNumberPtr = value; value->setParent(shared_from_this()); }
  MovementTitlePtr ScorePartwise::getMovementTitle() const { return _movementTitlePtr; }
  void ScorePartwise::setMovementTitle(const MovementTitlePtr& value) { _movementTitlePtr = value; value->setParent(shared_from_this()); }
  IdentificationPtr ScorePartwise::getIdentification() const { return _identificationPtr; }
  void ScorePartwise::setIdentification(const IdentificationPtr& value) { _identificationPtr = value; value->setParent(shared_from_this()); }
  DefaultsPtr ScorePartwise::getDefaults() const { return _defaultsPtr; }
  void ScorePartwise::setDefaults(const DefaultsPtr& value) { _defaultsPtr = value; value->setParent(shared_from_this()); }
  const CreditSet& ScorePartwise::getCreditSet() const {  return _creditSet; }
  void ScorePartwise::removeCredit(const CreditPtr& value) { if(value) { auto i = std::find_if(_creditSet.begin(), _creditSet.end(), [&](const CreditPtr& item) { return item==value; }); if(i!=_creditSet.end()) _creditSet.erase(i); } }
  void ScorePartwise::addCredit(const CreditPtr& value) { if(value) { _creditSet.push_back(value); value->setParent(shared_from_this()); } }
  void ScorePartwise::clearCreditSet() { _creditSet.clear(); }
  const PartListSet& ScorePartwise::getPartListSet() const {  return _partListSet; }
  void ScorePartwise::removePartList(const PartListPtr& value) { if(value) { auto i = std::find_if(_partListSet.begin(), _partListSet.end(), [&](const PartListPtr& item) { return item==value; }); if(i!=_partListSet.end()) _partListSet.erase(i); } }
  void ScorePartwise::addPartList(const PartListPtr& value) { if(value) { _partListSet.push_back(value); value->setParent(shared_from_this()); } }
  void ScorePartwise::clearPartListSet() { _partListSet.clear(); }
  const PartSet& ScorePartwise::getPartSet() const {  return _partSet; }
  void ScorePartwise::removePart(const PartPtr& value) { if(value) { auto i = std::find_if(_partSet.begin(), _partSet.end(), [&](const PartPtr& item) { return item==value; }); if(i!=_partSet.end()) _partSet.erase(i); } }
  void ScorePartwise::addPart(const PartPtr& value) { if(value) { _partSet.push_back(value); value->setParent(shared_from_this()); } }
  void ScorePartwise::clearPartSet() { _partSet.clear(); }

  void ScorePartwise::ostreamAttrs(pugi::xml_node& self) const
  {
    DocumentAttributes::ostreamAttrs(self);
  }
  void ScorePartwise::istreamAttrs(const pugi::xml_node& self)
  {
    DocumentAttributes::istreamAttrs(self);
  }
  void ScorePartwise::ostreamContents(pugi::xml_node& self) const
  {
    if(_workPtr) {
      auto child = self.append_child("work");
      _workPtr->ostream(child);
    }
    if(_movementNumberPtr) {
      auto child = self.append_child("movement-number");
      _movementNumberPtr->ostream(child);
    }
    if(_movementTitlePtr) {
      auto child = self.append_child("movement-title");
      _movementTitlePtr->ostream(child);
    }
    if(_identificationPtr) {
      auto child = self.append_child("identification");
      _identificationPtr->ostream(child);
    }
    if(_defaultsPtr) {
      auto child = self.append_child("defaults");
      _defaultsPtr->ostream(child);
    }
    for(auto item : _creditSet) {
      auto child = self.append_child("credit");
      item->ostream(child);
    }
    if(_partListSet.size()>0) {
        auto  node = self.append_child("part-list");
        for(auto item : _partListSet) {
          if(std::dynamic_pointer_cast<PartGroup>(item).get()) {
            auto child = node.append_child("part-group");
            item->ostream(child);
          }else if(std::dynamic_pointer_cast<ScorePart>(item).get()) {
            auto child = node.append_child("score-part");
            item->ostream(child);
          }
        }
     }
    for(auto item : _partSet) {
      auto child = self.append_child("part");
      item->ostream(child);
    }
  }
  void ScorePartwise::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "work")==0) {
        auto workPtr = std::make_shared<Work>();
        workPtr->istream(child);
        setWork(workPtr);
      }
      else if(strcmp(child.name(), "movement-number")==0) {
        auto movementNumberPtr = std::make_shared<MovementNumber>();
        movementNumberPtr->istream(child);
        setMovementNumber(movementNumberPtr);
      }
      else if(strcmp(child.name(), "movement-title")==0) {
        auto movementTitlePtr = std::make_shared<MovementTitle>();
        movementTitlePtr->istream(child);
        setMovementTitle(movementTitlePtr);
      }
      else if(strcmp(child.name(), "identification")==0) {
        auto identificationPtr = std::make_shared<Identification>();
        identificationPtr->istream(child);
        setIdentification(identificationPtr);
      }
      else if(strcmp(child.name(), "defaults")==0) {
        auto defaultsPtr = std::make_shared<Defaults>();
        defaultsPtr->istream(child);
        setDefaults(defaultsPtr);
      }
      else if(strcmp(child.name(), "credit")==0) {
        auto creditPtr = std::make_shared<Credit>();
        creditPtr->istream(child);
        addCredit(creditPtr);
      }
      else if(strcmp(child.name(), "part-list")==0) {
        for(auto node: child.children()) {
          if(strcmp(node.name(), "part-group")==0 ) {
            auto item = std::make_shared<PartGroup>();
            item->istream(node);
            addPartList(item);
          }else if(strcmp(node.name(), "score-part")==0 ) {
            auto item = std::make_shared<ScorePart>();
            item->istream(node);
            addPartList(item);
          }
        }
      }
      else if(strcmp(child.name(), "part")==0) {
        auto partPtr = std::make_shared<Part>();
        partPtr->istream(child);
        addPart(partPtr);
      }
    }
  }
}
