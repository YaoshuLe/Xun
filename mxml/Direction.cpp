#include "Direction.h"
#include <cstring>
#include "DirectionType.h"
#include "Offset.h"
#include "Footnote.h"
#include "Level.h"
#include "Voice.h"
#include "Staff.h"
#include "Sound.h"

namespace mxml
{
  Direction::Direction() {}
  const DirectionTypeSet& Direction::getDirectionTypeSet() const {  return _directionTypeSet; }
  void Direction::removeDirectionType(const DirectionTypePtr& value) { if(value) { auto i = std::find_if(_directionTypeSet.begin(), _directionTypeSet.end(), [&](const DirectionTypePtr& item) { return item==value; }); if(i!=_directionTypeSet.end()) _directionTypeSet.erase(i); } } 
  void Direction::addDirectionType(const DirectionTypePtr& value) { if(value) { _directionTypeSet.push_back(value); value->setParent(shared_from_this()); } }
  void Direction::clearDirectionTypeSet() { _directionTypeSet.clear(); }
  OffsetPtr Direction::getOffset() const { return _offsetPtr; }
  void Direction::setOffset(const OffsetPtr& value) { _offsetPtr = value; value->setParent(shared_from_this()); }
  FootnotePtr Direction::getFootnote() const { return _footnotePtr; }
  void Direction::setFootnote(const FootnotePtr& value) { _footnotePtr = value; value->setParent(shared_from_this()); }
  LevelPtr Direction::getLevel() const { return _levelPtr; }
  void Direction::setLevel(const LevelPtr& value) { _levelPtr = value; value->setParent(shared_from_this()); }
  VoicePtr Direction::getVoice() const { return _voicePtr; }
  void Direction::setVoice(const VoicePtr& value) { _voicePtr = value; value->setParent(shared_from_this()); }
  StaffPtr Direction::getStaff() const { return _staffPtr; }
  void Direction::setStaff(const StaffPtr& value) { _staffPtr = value; value->setParent(shared_from_this()); }
  SoundPtr Direction::getSound() const { return _soundPtr; }
  void Direction::setSound(const SoundPtr& value) { _soundPtr = value; value->setParent(shared_from_this()); }

  void Direction::ostreamAttrs(pugi::xml_node& self) const
  {
    Placement::ostreamAttrs(self);
    Directive::ostreamAttrs(self);
  }
  void Direction::istreamAttrs(const pugi::xml_node& self)
  {
    Placement::istreamAttrs(self);
    Directive::istreamAttrs(self);
  }
  void Direction::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _directionTypeSet) {
      auto child = self.append_child("direction-type");
      item->ostream(child);
    }
    if(_offsetPtr) {
      auto child = self.append_child("offset");
      _offsetPtr->ostream(child);
    }
    if(_footnotePtr) {
      auto child = self.append_child("footnote");
      _footnotePtr->ostream(child);
    }
    if(_levelPtr) {
      auto child = self.append_child("level");
      _levelPtr->ostream(child);
    }
    if(_voicePtr) {
      auto child = self.append_child("voice");
      _voicePtr->ostream(child);
    }
    if(_staffPtr) {
      auto child = self.append_child("staff");
      _staffPtr->ostream(child);
    }
    if(_soundPtr) {
      auto child = self.append_child("sound");
      _soundPtr->ostream(child);
    }
  }
  void Direction::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "direction-type")==0) {
        auto directionTypePtr = std::make_shared<DirectionType>();
        directionTypePtr->istream(child);
        addDirectionType(directionTypePtr);
      }
      else if(strcmp(child.name(), "offset")==0) {
        auto offsetPtr = std::make_shared<Offset>();
        offsetPtr->istream(child);
        setOffset(offsetPtr);
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
      else if(strcmp(child.name(), "voice")==0) {
        auto voicePtr = std::make_shared<Voice>();
        voicePtr->istream(child);
        setVoice(voicePtr);
      }
      else if(strcmp(child.name(), "staff")==0) {
        auto staffPtr = std::make_shared<Staff>();
        staffPtr->istream(child);
        setStaff(staffPtr);
      }
      else if(strcmp(child.name(), "sound")==0) {
        auto soundPtr = std::make_shared<Sound>();
        soundPtr->istream(child);
        setSound(soundPtr);
      }
    }
  }
}
