#include "Measure.h"
#include <cstring>
#include "Note.h"
#include "Backup.h"
#include "Forward.h"
#include "Direction.h"
#include "Attributes.h"
#include "Harmony.h"
#include "FiguredBass.h"
#include "Print.h"
#include "Sound.h"
#include "Barline.h"
#include "Grouping.h"
#include "Link.h"
#include "Bookmark.h"

namespace mxml
{
  Measure::Measure() {}
  const MusicDataSet& Measure::getMusicDataSet() const {  return _musicDataSet; }
  void Measure::removeMusicData(const MusicDataPtr& value) { if(value) { auto i = std::find_if(_musicDataSet.begin(), _musicDataSet.end(), [&](const MusicDataPtr& item) { return item==value; }); if(i!=_musicDataSet.end()) _musicDataSet.erase(i); } }
  void Measure::addMusicData(const MusicDataPtr& value) { if(value) { _musicDataSet.push_back(value); value->setParent(shared_from_this()); } }
  void Measure::clearMusicDataSet() { _musicDataSet.clear(); }

  void Measure::ostreamAttrs(pugi::xml_node& self) const
  {
    MeasureAttributes::ostreamAttrs(self);
  }
  void Measure::istreamAttrs(const pugi::xml_node& self)
  {
    MeasureAttributes::istreamAttrs(self);
  }
  void Measure::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _musicDataSet) {
      if(std::dynamic_pointer_cast<Note>(item).get()) {
        auto child = self.append_child("note");
        item->ostream(child);
      }else if(std::dynamic_pointer_cast<Backup>(item).get()) {
        auto child = self.append_child("backup");
        item->ostream(child);
      }else if(std::dynamic_pointer_cast<Forward>(item).get()) {
        auto child = self.append_child("forward");
        item->ostream(child);
      }else if(std::dynamic_pointer_cast<Direction>(item).get()) {
        auto child = self.append_child("direction");
        item->ostream(child);
      }else if(std::dynamic_pointer_cast<Attributes>(item).get()) {
        auto child = self.append_child("attributes");
        item->ostream(child);
      }else if(std::dynamic_pointer_cast<Harmony>(item).get()) {
        auto child = self.append_child("harmony");
        item->ostream(child);
      }else if(std::dynamic_pointer_cast<FiguredBass>(item).get()) {
        auto child = self.append_child("figured-bass");
        item->ostream(child);
      }else if(std::dynamic_pointer_cast<Print>(item).get()) {
        auto child = self.append_child("print");
        item->ostream(child);
      }else if(std::dynamic_pointer_cast<Sound>(item).get()) {
        auto child = self.append_child("sound");
        item->ostream(child);
      }else if(std::dynamic_pointer_cast<Barline>(item).get()) {
        auto child = self.append_child("barline");
        item->ostream(child);
      }else if(std::dynamic_pointer_cast<Grouping>(item).get()) {
        auto child = self.append_child("grouping");
        item->ostream(child);
      }else if(std::dynamic_pointer_cast<Link>(item).get()) {
        auto child = self.append_child("link");
        item->ostream(child);
      }else if(std::dynamic_pointer_cast<Bookmark>(item).get()) {
        auto child = self.append_child("bookmark");
        item->ostream(child);
      }
    }
  }
  void Measure::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "note")==0) {
        auto item = std::make_shared<Note>();
        item->istream(child);
        addMusicData(item);
      }else if(strcmp(child.name(), "backup")==0) {
        auto item = std::make_shared<Backup>();
        item->istream(child);
        addMusicData(item);
      }else if(strcmp(child.name(), "forward")==0) {
        auto item = std::make_shared<Forward>();
        item->istream(child);
        addMusicData(item);
      }else if(strcmp(child.name(), "direction")==0) {
        auto item = std::make_shared<Direction>();
        item->istream(child);
        addMusicData(item);
      }else if(strcmp(child.name(), "attributes")==0) {
        auto item = std::make_shared<Attributes>();
        item->istream(child);
        addMusicData(item);
      }else if(strcmp(child.name(), "harmony")==0) {
        auto item = std::make_shared<Harmony>();
        item->istream(child);
        addMusicData(item);
      }else if(strcmp(child.name(), "figured-bass")==0) {
        auto item = std::make_shared<FiguredBass>();
        item->istream(child);
        addMusicData(item);
      }else if(strcmp(child.name(), "print")==0) {
        auto item = std::make_shared<Print>();
        item->istream(child);
        addMusicData(item);
      }else if(strcmp(child.name(), "sound")==0) {
        auto item = std::make_shared<Sound>();
        item->istream(child);
        addMusicData(item);
      }else if(strcmp(child.name(), "barline")==0) {
        auto item = std::make_shared<Barline>();
        item->istream(child);
        addMusicData(item);
      }else if(strcmp(child.name(), "grouping")==0) {
        auto item = std::make_shared<Grouping>();
        item->istream(child);
        addMusicData(item);
      }else if(strcmp(child.name(), "link")==0) {
        auto item = std::make_shared<Link>();
        item->istream(child);
        addMusicData(item);
      }else if(strcmp(child.name(), "bookmark")==0) {
        auto item = std::make_shared<Bookmark>();
        item->istream(child);
        addMusicData(item);
      }
    }
  }
}
#include "Part.h"
#include "Attributes.h"
#include "StaffDetails.h"
#include "Clef.h"
#include "Key.h"
namespace mxml
{
  MeasurePtr Measure::getNextMeasure() const
  {
    MeasurePtr rtn;
    auto measures = this->getParent<Part>()->getMeasureSet();
    auto iterator = ++std::find(measures.cbegin(), measures.cend(), shared_from_this());
    if(iterator!=measures.cend()) {
        return *iterator;
    }
    return rtn;
  }
  MeasurePtr Measure::getPrevMeasure() const
  {
    MeasurePtr rtn;
    auto measures = this->getParent<Part>()->getMeasureSet();
    auto iterator = MeasureSet::const_reverse_iterator(std::find(measures.cbegin(), measures.cend(), shared_from_this()));
    if(iterator!=measures.crend()) {
        return *iterator;
    }
    return rtn;
  }
  StaffDetailsPtr Measure::getStaffDetails(int snb) const
  {
    StaffDetailsPtr rtn;
    auto measures = this->getParent<Part>()->getMeasureSet();
    for(auto iterator = MeasureSet::const_reverse_iterator(++std::find(measures.cbegin(), measures.cend(), shared_from_this())); iterator!=measures.crend(); ++iterator) {
        for(auto musicData : (*iterator)->getMusicDataSet()) {
            if(std::dynamic_pointer_cast<mxml::Attributes>(musicData).get()) {
                for(auto staffDetails : std::dynamic_pointer_cast<mxml::Attributes>(musicData)->getStaffDetailsSet()) {
                    if(snb==(staffDetails->hasNumber()?staffDetails->number():1)) {
                        rtn = staffDetails;
                        goto FOR_BREAK;
                    }
                }
            }
        }
    }
    FOR_BREAK:
    return rtn;
  }
  ClefPtr Measure::getClef(int snb) const
  {
    ClefPtr rtn;
    auto measures = this->getParent<Part>()->getMeasureSet();
    for(auto iterator = MeasureSet::const_reverse_iterator(++std::find(measures.cbegin(), measures.cend(), shared_from_this())); iterator!=measures.crend(); ++iterator) {
        for(auto musicData : (*iterator)->getMusicDataSet()) {
            if(std::dynamic_pointer_cast<mxml::Attributes>(musicData).get()) {
                for(auto clef : std::dynamic_pointer_cast<mxml::Attributes>(musicData)->getClefSet()) {
                    if(snb==(clef->hasNumber()?clef->number():1)) {
                        rtn = clef;
                        goto FOR_BREAK;
                    }
                }
            }
        }
    }
    FOR_BREAK:
    return rtn;
  }
  KeyPtr Measure::getKey(int snb) const
  {
    KeyPtr rtn;
    auto measures = this->getParent<Part>()->getMeasureSet();
    for(auto iterator = MeasureSet::const_reverse_iterator(++std::find(measures.cbegin(), measures.cend(), shared_from_this())); iterator!=measures.crend(); ++iterator) {
        for(auto musicData : (*iterator)->getMusicDataSet()) {
            if(std::dynamic_pointer_cast<mxml::Attributes>(musicData).get()) {
                for(auto key : std::dynamic_pointer_cast<mxml::Attributes>(musicData)->getKeySet()) {
                    if(snb==(key->hasNumber()?key->number():1)) {
                        rtn = key;
                        goto FOR_BREAK;
                    }
                }
            }
        }
    }
    FOR_BREAK:
    return rtn;
  }
}
