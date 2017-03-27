#include "PartGroup.h"
#include <cstring>
#include "GroupName.h"
#include "GroupNameDisplay.h"
#include "GroupAbbreviation.h"
#include "GroupAbbreviationDisplay.h"
#include "GroupSymbol.h"
#include "GroupBarline.h"
#include "GroupTime.h"
#include "Footnote.h"
#include "Level.h"

namespace mxml
{
  PartGroup::PartGroup() {}
  GroupNamePtr PartGroup::getGroupName() const { return _groupNamePtr; }
  void PartGroup::setGroupName(const GroupNamePtr& value) { _groupNamePtr = value; value->setParent(shared_from_this()); }
  GroupNameDisplayPtr PartGroup::getGroupNameDisplay() const { return _groupNameDisplayPtr; }
  void PartGroup::setGroupNameDisplay(const GroupNameDisplayPtr& value) { _groupNameDisplayPtr = value; value->setParent(shared_from_this()); }
  GroupAbbreviationPtr PartGroup::getGroupAbbreviation() const { return _groupAbbreviationPtr; }
  void PartGroup::setGroupAbbreviation(const GroupAbbreviationPtr& value) { _groupAbbreviationPtr = value; value->setParent(shared_from_this()); }
  GroupAbbreviationDisplayPtr PartGroup::getGroupAbbreviationDisplay() const { return _groupAbbreviationDisplayPtr; }
  void PartGroup::setGroupAbbreviationDisplay(const GroupAbbreviationDisplayPtr& value) { _groupAbbreviationDisplayPtr = value; value->setParent(shared_from_this()); }
  GroupSymbolPtr PartGroup::getGroupSymbol() const { return _groupSymbolPtr; }
  void PartGroup::setGroupSymbol(const GroupSymbolPtr& value) { _groupSymbolPtr = value; value->setParent(shared_from_this()); }
  GroupBarlinePtr PartGroup::getGroupBarline() const { return _groupBarlinePtr; }
  void PartGroup::setGroupBarline(const GroupBarlinePtr& value) { _groupBarlinePtr = value; value->setParent(shared_from_this()); }
  GroupTimePtr PartGroup::getGroupTime() const { return _groupTimePtr; }
  void PartGroup::setGroupTime(const GroupTimePtr& value) { _groupTimePtr = value; value->setParent(shared_from_this()); }
  FootnotePtr PartGroup::getFootnote() const { return _footnotePtr; }
  void PartGroup::setFootnote(const FootnotePtr& value) { _footnotePtr = value; value->setParent(shared_from_this()); }
  LevelPtr PartGroup::getLevel() const { return _levelPtr; }
  void PartGroup::setLevel(const LevelPtr& value) { _levelPtr = value; value->setParent(shared_from_this()); }
  bool PartGroup::hasType() const { return _hasType; }
  void PartGroup::hasType(bool value) { _hasType = value; }
  StartStopEnum PartGroup::type() const { return _type; }
  void PartGroup::type(StartStopEnum value) { _type = value; }
  bool PartGroup::hasNumber() const { return _hasNumber; }
  void PartGroup::hasNumber(bool value) { _hasNumber = value; }
  std::string PartGroup::number() const { return _number; }
  void PartGroup::number(std::string value) { _number = value; }

  void PartGroup::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasNumber) {
      self.append_attribute("number").set_value(_number.c_str());
    }
  }
  void PartGroup::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = StartStopEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("number")) {
      _number = attr.as_string();
      _hasNumber = true;
    }
  }
  void PartGroup::ostreamContents(pugi::xml_node& self) const
  {
    if(_groupNamePtr) {
      auto child = self.append_child("group-name");
      _groupNamePtr->ostream(child);
    }
    if(_groupNameDisplayPtr) {
      auto child = self.append_child("group-name-display");
      _groupNameDisplayPtr->ostream(child);
    }
    if(_groupAbbreviationPtr) {
      auto child = self.append_child("group-abbreviation");
      _groupAbbreviationPtr->ostream(child);
    }
    if(_groupAbbreviationDisplayPtr) {
      auto child = self.append_child("group-abbreviation-display");
      _groupAbbreviationDisplayPtr->ostream(child);
    }
    if(_groupSymbolPtr) {
      auto child = self.append_child("group-symbol");
      _groupSymbolPtr->ostream(child);
    }
    if(_groupBarlinePtr) {
      auto child = self.append_child("group-barline");
      _groupBarlinePtr->ostream(child);
    }
    if(_groupTimePtr) {
      auto child = self.append_child("group-time");
      _groupTimePtr->ostream(child);
    }
    if(_footnotePtr) {
      auto child = self.append_child("footnote");
      _footnotePtr->ostream(child);
    }
    if(_levelPtr) {
      auto child = self.append_child("level");
      _levelPtr->ostream(child);
    }
  }
  void PartGroup::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "group-name")==0) {
        auto groupNamePtr = std::make_shared<GroupName>();
        groupNamePtr->istream(child);
        setGroupName(groupNamePtr);
      }
      else if(strcmp(child.name(), "group-name-display")==0) {
        auto groupNameDisplayPtr = std::make_shared<GroupNameDisplay>();
        groupNameDisplayPtr->istream(child);
        setGroupNameDisplay(groupNameDisplayPtr);
      }
      else if(strcmp(child.name(), "group-abbreviation")==0) {
        auto groupAbbreviationPtr = std::make_shared<GroupAbbreviation>();
        groupAbbreviationPtr->istream(child);
        setGroupAbbreviation(groupAbbreviationPtr);
      }
      else if(strcmp(child.name(), "group-abbreviation-display")==0) {
        auto groupAbbreviationDisplayPtr = std::make_shared<GroupAbbreviationDisplay>();
        groupAbbreviationDisplayPtr->istream(child);
        setGroupAbbreviationDisplay(groupAbbreviationDisplayPtr);
      }
      else if(strcmp(child.name(), "group-symbol")==0) {
        auto groupSymbolPtr = std::make_shared<GroupSymbol>();
        groupSymbolPtr->istream(child);
        setGroupSymbol(groupSymbolPtr);
      }
      else if(strcmp(child.name(), "group-barline")==0) {
        auto groupBarlinePtr = std::make_shared<GroupBarline>();
        groupBarlinePtr->istream(child);
        setGroupBarline(groupBarlinePtr);
      }
      else if(strcmp(child.name(), "group-time")==0) {
        auto groupTimePtr = std::make_shared<GroupTime>();
        groupTimePtr->istream(child);
        setGroupTime(groupTimePtr);
      }
      else if(strcmp(child.name(), "footnote")==0) {
        auto footnotePtr = std::make_shared<Footnote>();
        footnotePtr->istream(child);
        setFootnote(footnotePtr);
      }
      else if(strcmp(child.name(), "level")==0) {
        auto levelPtr = std::make_shared<Level>();
        levelPtr->istream(child);
        setLevel(levelPtr);
      }
    }
  }
}
