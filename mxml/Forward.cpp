#include "Forward.h"
#include <cstring>
#include "Duration.h"
#include "Footnote.h"
#include "Level.h"
#include "Voice.h"
#include "Staff.h"

namespace mxml
{
  Forward::Forward() {}
  DurationPtr Forward::getDuration() const { return _durationPtr; }
  void Forward::setDuration(const DurationPtr& value) { _durationPtr = value; value->setParent(shared_from_this()); }
  FootnotePtr Forward::getFootnote() const { return _footnotePtr; }
  void Forward::setFootnote(const FootnotePtr& value) { _footnotePtr = value; value->setParent(shared_from_this()); }
  LevelPtr Forward::getLevel() const { return _levelPtr; }
  void Forward::setLevel(const LevelPtr& value) { _levelPtr = value; value->setParent(shared_from_this()); }
  VoicePtr Forward::getVoice() const { return _voicePtr; }
  void Forward::setVoice(const VoicePtr& value) { _voicePtr = value; value->setParent(shared_from_this()); }
  StaffPtr Forward::getStaff() const { return _staffPtr; }
  void Forward::setStaff(const StaffPtr& value) { _staffPtr = value; value->setParent(shared_from_this()); }

  void Forward::ostreamContents(pugi::xml_node& self) const
  {
    if(_durationPtr) {
      auto child = self.append_child("duration");
      _durationPtr->ostream(child);
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
  }
  void Forward::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "duration")==0) {
        auto durationPtr = std::make_shared<Duration>();
        durationPtr->istream(child);
        setDuration(durationPtr);
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
    }
  }
}
