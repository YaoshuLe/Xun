#include "BeatRepeat.h"
#include <cstring>
#include "SlashType.h"
#include "SlashDot.h"

namespace mxml
{
  BeatRepeat::BeatRepeat() {}
  SlashTypePtr BeatRepeat::getSlashType() const { return _slashTypePtr; }
  void BeatRepeat::setSlashType(const SlashTypePtr& value) { _slashTypePtr = value; value->setParent(shared_from_this()); }
  const SlashDotSet& BeatRepeat::getSlashDotSet() const {  return _slashDotSet; }
  void BeatRepeat::removeSlashDot(const SlashDotPtr& value) { if(value) { auto i = std::find_if(_slashDotSet.begin(), _slashDotSet.end(), [&](const SlashDotPtr& item) { return item==value; }); if(i!=_slashDotSet.end()) _slashDotSet.erase(i); } } 
  void BeatRepeat::addSlashDot(const SlashDotPtr& value) { if(value) { _slashDotSet.push_back(value); value->setParent(shared_from_this()); } }
  void BeatRepeat::clearSlashDotSet() { _slashDotSet.clear(); }
  bool BeatRepeat::hasType() const { return _hasType; }
  void BeatRepeat::hasType(bool value) { _hasType = value; }
  StartStopEnum BeatRepeat::type() const { return _type; }
  void BeatRepeat::type(StartStopEnum value) { _type = value; }
  bool BeatRepeat::hasSlashes() const { return _hasSlashes; }
  void BeatRepeat::hasSlashes(bool value) { _hasSlashes = value; }
  int BeatRepeat::slashes() const { return _slashes; }
  void BeatRepeat::slashes(int value) { _slashes = value; }
  bool BeatRepeat::hasUseDots() const { return _hasUseDots; }
  void BeatRepeat::hasUseDots(bool value) { _hasUseDots = value; }
  YesNoEnum BeatRepeat::useDots() const { return _useDots; }
  void BeatRepeat::useDots(YesNoEnum value) { _useDots = value; }

  void BeatRepeat::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasSlashes) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _slashes);
      self.append_attribute("slashes").set_value(str);
    }
    if(_hasUseDots) {
      self.append_attribute("use-dots").set_value(_useDots.operator const char *());
    }
  }
  void BeatRepeat::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = StartStopEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("slashes")) {
      _slashes = attr.as_int();
      _hasSlashes = true;
    }
    if(auto attr = self.attribute("use-dots")) {
      _useDots = YesNoEnum(attr.as_string());
      _hasUseDots = true;
    }
  }
  void BeatRepeat::ostreamContents(pugi::xml_node& self) const
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
  void BeatRepeat::istreamContents(const pugi::xml_node& self)
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
