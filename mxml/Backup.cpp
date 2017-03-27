#include "Backup.h"
#include <cstring>
#include "Duration.h"
#include "Footnote.h"
#include "Level.h"

namespace mxml
{
  Backup::Backup() {}
  DurationPtr Backup::getDuration() const { return _durationPtr; }
  void Backup::setDuration(const DurationPtr& value) { _durationPtr = value; value->setParent(shared_from_this()); }
  FootnotePtr Backup::getFootnote() const { return _footnotePtr; }
  void Backup::setFootnote(const FootnotePtr& value) { _footnotePtr = value; value->setParent(shared_from_this()); }
  LevelPtr Backup::getLevel() const { return _levelPtr; }
  void Backup::setLevel(const LevelPtr& value) { _levelPtr = value; value->setParent(shared_from_this()); }

  void Backup::ostreamContents(pugi::xml_node& self) const
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
  }
  void Backup::istreamContents(const pugi::xml_node& self)
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
    }
  }
}
