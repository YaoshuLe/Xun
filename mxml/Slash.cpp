#include "Slash.h"
#include <cstring>
#include "SlashType.h"
#include "SlashDot.h"

namespace mxml
{
  Slash::Slash() {}
  SlashTypePtr Slash::getSlashType() const { return _slashTypePtr; }
  void Slash::setSlashType(const SlashTypePtr& value) { _slashTypePtr = value; value->setParent(shared_from_this()); }
  const SlashDotSet& Slash::getSlashDotSet() const {  return _slashDotSet; }
  void Slash::removeSlashDot(const SlashDotPtr& value) { if(value) { auto i = std::find_if(_slashDotSet.begin(), _slashDotSet.end(), [&](const SlashDotPtr& item) { return item==value; }); if(i!=_slashDotSet.end()) _slashDotSet.erase(i); } } 
  void Slash::addSlashDot(const SlashDotPtr& value) { if(value) { _slashDotSet.push_back(value); value->setParent(shared_from_this()); } }
  void Slash::clearSlashDotSet() { _slashDotSet.clear(); }
  bool Slash::hasType() const { return _hasType; }
  void Slash::hasType(bool value) { _hasType = value; }
  StartStopEnum Slash::type() const { return _type; }
  void Slash::type(StartStopEnum value) { _type = value; }
  bool Slash::hasUseDots() const { return _hasUseDots; }
  void Slash::hasUseDots(bool value) { _hasUseDots = value; }
  YesNoEnum Slash::useDots() const { return _useDots; }
  void Slash::useDots(YesNoEnum value) { _useDots = value; }
  bool Slash::hasUseStems() const { return _hasUseStems; }
  void Slash::hasUseStems(bool value) { _hasUseStems = value; }
  YesNoEnum Slash::useStems() const { return _useStems; }
  void Slash::useStems(YesNoEnum value) { _useStems = value; }

  void Slash::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasUseDots) {
      self.append_attribute("use-dots").set_value(_useDots.operator const char *());
    }
    if(_hasUseStems) {
      self.append_attribute("use-stems").set_value(_useStems.operator const char *());
    }
  }
  void Slash::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = StartStopEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("use-dots")) {
      _useDots = YesNoEnum(attr.as_string());
      _hasUseDots = true;
    }
    if(auto attr = self.attribute("use-stems")) {
      _useStems = YesNoEnum(attr.as_string());
      _hasUseStems = true;
    }
  }
  void Slash::ostreamContents(pugi::xml_node& self) const
  {
    if(_slashTypePtr) {
      auto child = self.append_child("slash-type");
      _slashTypePtr->ostream(child);
    }
    for(auto item : _slashDotSet) {
      auto child = self.append_child("slash-dot");
      item->ostream(child);
    }
  }
  void Slash::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "slash-type")==0) {
        auto slashTypePtr = std::make_shared<SlashType>();
        slashTypePtr->istream(child);
        setSlashType(slashTypePtr);
      }
      else if(strcmp(child.name(), "slash-dot")==0) {
        auto slashDotPtr = std::make_shared<SlashDot>();
        slashDotPtr->istream(child);
        addSlashDot(slashDotPtr);
      }
    }
  }
}
