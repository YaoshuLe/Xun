#include "Note.h"
#include <cstring>
#include "Grace.h"
#include "Chord.h"
#include "Pitch.h"
#include "Unpitched.h"
#include "Rest.h"
#include "Tie.h"
#include "Cue.h"
#include "Duration.h"
#include "Instrument.h"
#include "Footnote.h"
#include "Level.h"
#include "Voice.h"
#include "Type.h"
#include "Dot.h"
#include "Accidental.h"
#include "TimeModification.h"
#include "Stem.h"
#include "Notehead.h"
#include "NoteheadText.h"
#include "Staff.h"
#include "Beam.h"
#include "Notations.h"
#include "Lyric.h"
#include "Ipa.h"
#include "Mute.h"
#include "SemiPitched.h"
#include "OtherPlay.h"

namespace mxml
{
  Note::Note() {}
  GracePtr Note::getGrace() const { return _gracePtr; }
  void Note::setGrace(const GracePtr& value) { _gracePtr = value; value->setParent(shared_from_this()); }
  CuePtr Note::getCue() const { return _cuePtr; }
  void Note::setCue(const CuePtr& value) { _cuePtr = value; value->setParent(shared_from_this()); }
  ChordPtr Note::getChord() const { return _chordPtr; }
  void Note::setChord(const ChordPtr& value) { _chordPtr = value; value->setParent(shared_from_this()); }
  PitchPtr Note::getPitch() const { return _pitchPtr; }
  void Note::setPitch(const PitchPtr& value) { _pitchPtr = value; value->setParent(shared_from_this()); }
  UnpitchedPtr Note::getUnpitched() const { return _unpitchedPtr; }
  void Note::setUnpitched(const UnpitchedPtr& value) { _unpitchedPtr = value; value->setParent(shared_from_this()); }
  RestPtr Note::getRest() const { return _restPtr; }
  void Note::setRest(const RestPtr& value) { _restPtr = value; value->setParent(shared_from_this()); }
  const TieSet& Note::getTieSet() const {  return _tieSet; }
  void Note::removeTie(const TiePtr& value) { if(value) { auto i = std::find_if(_tieSet.begin(), _tieSet.end(), [&](const TiePtr& item) { return item==value; }); if(i!=_tieSet.end()) _tieSet.erase(i); } }
  void Note::addTie(const TiePtr& value) { if(value) { _tieSet.push_back(value); value->setParent(shared_from_this()); } }
  void Note::clearTieSet() { _tieSet.clear(); }
  DurationPtr Note::getDuration() const { return _durationPtr; }
  void Note::setDuration(const DurationPtr& value) { _durationPtr = value; value->setParent(shared_from_this()); }
  InstrumentPtr Note::getInstrument() const { return _instrumentPtr; }
  void Note::setInstrument(const InstrumentPtr& value) { _instrumentPtr = value; value->setParent(shared_from_this()); }
  FootnotePtr Note::getFootnote() const { return _footnotePtr; }
  void Note::setFootnote(const FootnotePtr& value) { _footnotePtr = value; value->setParent(shared_from_this()); }
  LevelPtr Note::getLevel() const { return _levelPtr; }
  void Note::setLevel(const LevelPtr& value) { _levelPtr = value; value->setParent(shared_from_this()); }
  VoicePtr Note::getVoice() const { return _voicePtr; }
  void Note::setVoice(const VoicePtr& value) { _voicePtr = value; value->setParent(shared_from_this()); }
  TypePtr Note::getType() const { return _typePtr; }
  void Note::setType(const TypePtr& value) { _typePtr = value; value->setParent(shared_from_this()); }
  const DotSet& Note::getDotSet() const {  return _dotSet; }
  void Note::removeDot(const DotPtr& value) { if(value) { auto i = std::find_if(_dotSet.begin(), _dotSet.end(), [&](const DotPtr& item) { return item==value; }); if(i!=_dotSet.end()) _dotSet.erase(i); } }
  void Note::addDot(const DotPtr& value) { if(value) { _dotSet.push_back(value); value->setParent(shared_from_this()); } }
  void Note::clearDotSet() { _dotSet.clear(); }
  AccidentalPtr Note::getAccidental() const { return _accidentalPtr; }
  void Note::setAccidental(const AccidentalPtr& value) { _accidentalPtr = value; value->setParent(shared_from_this()); }
  TimeModificationPtr Note::getTimeModification() const { return _timeModificationPtr; }
  void Note::setTimeModification(const TimeModificationPtr& value) { _timeModificationPtr = value; value->setParent(shared_from_this()); }
  StemPtr Note::getStem() const { return _stemPtr; }
  void Note::setStem(const StemPtr& value) { _stemPtr = value; value->setParent(shared_from_this()); }
  NoteheadPtr Note::getNotehead() const { return _noteheadPtr; }
  void Note::setNotehead(const NoteheadPtr& value) { _noteheadPtr = value; value->setParent(shared_from_this()); }
  NoteheadTextPtr Note::getNoteheadText() const { return _noteheadTextPtr; }
  void Note::setNoteheadText(const NoteheadTextPtr& value) { _noteheadTextPtr = value; value->setParent(shared_from_this()); }
  StaffPtr Note::getStaff() const { return _staffPtr; }
  void Note::setStaff(const StaffPtr& value) { _staffPtr = value; value->setParent(shared_from_this()); }
  const BeamSet& Note::getBeamSet() const {  return _beamSet; }
  void Note::removeBeam(const BeamPtr& value) { if(value) { auto i = std::find_if(_beamSet.begin(), _beamSet.end(), [&](const BeamPtr& item) { return item==value; }); if(i!=_beamSet.end()) _beamSet.erase(i); } }
  void Note::addBeam(const BeamPtr& value) { if(value) { _beamSet.push_back(value); value->setParent(shared_from_this()); } }
  void Note::clearBeamSet() { _beamSet.clear(); }
  const NotationsSet& Note::getNotationsSet() const {  return _notationsSet; }
  void Note::removeNotations(const NotationsPtr& value) { if(value) { auto i = std::find_if(_notationsSet.begin(), _notationsSet.end(), [&](const NotationsPtr& item) { return item==value; }); if(i!=_notationsSet.end()) _notationsSet.erase(i); } }
  void Note::addNotations(const NotationsPtr& value) { if(value) { _notationsSet.push_back(value); value->setParent(shared_from_this()); } }
  void Note::clearNotationsSet() { _notationsSet.clear(); }
  const LyricSet& Note::getLyricSet() const {  return _lyricSet; }
  void Note::removeLyric(const LyricPtr& value) { if(value) { auto i = std::find_if(_lyricSet.begin(), _lyricSet.end(), [&](const LyricPtr& item) { return item==value; }); if(i!=_lyricSet.end()) _lyricSet.erase(i); } }
  void Note::addLyric(const LyricPtr& value) { if(value) { _lyricSet.push_back(value); value->setParent(shared_from_this()); } }
  void Note::clearLyricSet() { _lyricSet.clear(); }
  const PlaySet& Note::getPlaySet() const {  return _playSet; }
  void Note::removePlay(const PlayPtr& value) { if(value) { auto i = std::find_if(_playSet.begin(), _playSet.end(), [&](const PlayPtr& item) { return item==value; }); if(i!=_playSet.end()) _playSet.erase(i); } }
  void Note::addPlay(const PlayPtr& value) { if(value) { _playSet.push_back(value); value->setParent(shared_from_this()); } }
  void Note::clearPlaySet() { _playSet.clear(); }
  bool Note::hasDynamics() const { return _hasDynamics; }
  void Note::hasDynamics(bool value) { _hasDynamics = value; }
  float Note::dynamics() const { return _dynamics; }
  void Note::dynamics(float value) { _dynamics = value; }
  bool Note::hasEndDynamics() const { return _hasEndDynamics; }
  void Note::hasEndDynamics(bool value) { _hasEndDynamics = value; }
  float Note::endDynamics() const { return _endDynamics; }
  void Note::endDynamics(float value) { _endDynamics = value; }
  bool Note::hasAttack() const { return _hasAttack; }
  void Note::hasAttack(bool value) { _hasAttack = value; }
  float Note::attack() const { return _attack; }
  void Note::attack(float value) { _attack = value; }
  bool Note::hasRelease() const { return _hasRelease; }
  void Note::hasRelease(bool value) { _hasRelease = value; }
  float Note::release() const { return _release; }
  void Note::release(float value) { _release = value; }
  bool Note::hasTimeOnly() const { return _hasTimeOnly; }
  void Note::hasTimeOnly(bool value) { _hasTimeOnly = value; }
  std::string Note::timeOnly() const { return _timeOnly; }
  void Note::timeOnly(std::string value) { _timeOnly = value; }
  bool Note::hasPizzicato() const { return _hasPizzicato; }
  void Note::hasPizzicato(bool value) { _hasPizzicato = value; }
  YesNoEnum Note::pizzicato() const { return _pizzicato; }
  void Note::pizzicato(YesNoEnum value) { _pizzicato = value; }
  bool Note::hasPlayId() const { return _hasPlayId; }
  void Note::hasPlayId(bool value) { _hasPlayId = value; }
  std::string Note::playId() const { return _playId; }
  void Note::playId(std::string value) { _playId = value; }

  void Note::ostreamAttrs(pugi::xml_node& self) const
  {
    XPosition::ostreamAttrs(self);
    Font::ostreamAttrs(self);
    Color::ostreamAttrs(self);
    Printout::ostreamAttrs(self);
    if(_hasDynamics) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _dynamics);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("dynamics").set_value(str);
    }
    if(_hasEndDynamics) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _endDynamics);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("end-dynamics").set_value(str);
    }
    if(_hasAttack) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _attack);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("attack").set_value(str);
    }
    if(_hasRelease) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _release);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("release").set_value(str);
    }
    if(_hasTimeOnly) {
      self.append_attribute("time-only").set_value(_timeOnly.c_str());
    }
    if(_hasPizzicato) {
      self.append_attribute("pizzicato").set_value(_pizzicato.operator const char *());
    }
  }
  void Note::istreamAttrs(const pugi::xml_node& self)
  {
    XPosition::istreamAttrs(self);
    Font::istreamAttrs(self);
    Color::istreamAttrs(self);
    Printout::istreamAttrs(self);
    if(auto attr = self.attribute("dynamics")) {
      _dynamics = attr.as_float();
      _hasDynamics = true;
    }
    if(auto attr = self.attribute("end-dynamics")) {
      _endDynamics = attr.as_float();
      _hasEndDynamics = true;
    }
    if(auto attr = self.attribute("attack")) {
      _attack = attr.as_float();
      _hasAttack = true;
    }
    if(auto attr = self.attribute("release")) {
      _release = attr.as_float();
      _hasRelease = true;
    }
    if(auto attr = self.attribute("time-only")) {
      _timeOnly = attr.as_string();
      _hasTimeOnly = true;
    }
    if(auto attr = self.attribute("pizzicato")) {
      _pizzicato = YesNoEnum(attr.as_string());
      _hasPizzicato = true;
    }
  }
  void Note::ostreamContents(pugi::xml_node& self) const
  {
    if(_gracePtr) {
      auto child = self.append_child("grace");
      _gracePtr->ostream(child);
      if(_chordPtr) {
        auto child = self.append_child("chord");
        _chordPtr->ostream(child);
      }
      if(_pitchPtr) {
        auto child = self.append_child("pitch");
        _pitchPtr->ostream(child);
      }
      else if(_unpitchedPtr) {
        auto child = self.append_child("unpitched");
        _unpitchedPtr->ostream(child);
      }
      else if(_restPtr) {
        auto child = self.append_child("rest");
        _restPtr->ostream(child);
      }
      for(auto item : _tieSet) {
        auto child = self.append_child("tie");
        item->ostream(child);
      }
    }
    else if(_cuePtr) {
      auto child = self.append_child("cue");
      _cuePtr->ostream(child);
      if(_chordPtr) {
        auto child = self.append_child("chord");
        _chordPtr->ostream(child);
      }
      if(_pitchPtr) {
        auto child = self.append_child("pitch");
        _pitchPtr->ostream(child);
      }
      else if(_unpitchedPtr) {
        auto child = self.append_child("unpitched");
        _unpitchedPtr->ostream(child);
      }
      else if(_restPtr) {
        auto child = self.append_child("rest");
        _restPtr->ostream(child);
      }
      if(_durationPtr) {
        auto child = self.append_child("duration");
        _durationPtr->ostream(child);
      }
    }
    else {
      if(_chordPtr) {
        auto child = self.append_child("chord");
        _chordPtr->ostream(child);
      }
      if(_pitchPtr) {
        auto child = self.append_child("pitch");
        _pitchPtr->ostream(child);
      }
      else if(_unpitchedPtr) {
        auto child = self.append_child("unpitched");
        _unpitchedPtr->ostream(child);
      }
      else if(_restPtr) {
        auto child = self.append_child("rest");
        _restPtr->ostream(child);
      }
      if(_durationPtr) {
        auto child = self.append_child("duration");
        _durationPtr->ostream(child);
      }
      for(auto item : _tieSet) {
        auto child = self.append_child("tie");
        item->ostream(child);
      }
    }
    if(_instrumentPtr) {
      auto child = self.append_child("instrument");
      _instrumentPtr->ostream(child);
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
    if(_typePtr) {
      auto child = self.append_child("type");
      _typePtr->ostream(child);
    }
    for(auto item : _dotSet) {
      auto child = self.append_child("dot");
      item->ostream(child);
    }
    if(_accidentalPtr) {
      auto child = self.append_child("accidental");
      _accidentalPtr->ostream(child);
    }
    if(_timeModificationPtr) {
      auto child = self.append_child("time-modification");
      _timeModificationPtr->ostream(child);
    }
    if(_stemPtr) {
      auto child = self.append_child("stem");
      _stemPtr->ostream(child);
    }
    if(_noteheadPtr) {
      auto child = self.append_child("notehead");
      _noteheadPtr->ostream(child);
    }
    if(_noteheadTextPtr) {
      auto child = self.append_child("notehead-text");
      _noteheadTextPtr->ostream(child);
    }
    if(_staffPtr) {
      auto child = self.append_child("staff");
      _staffPtr->ostream(child);
    }
    for(auto item : _beamSet) {
      auto child = self.append_child("beam");
      item->ostream(child);
    }
    for(auto item : _notationsSet) {
      auto child = self.append_child("notations");
      item->ostream(child);
    }
    for(auto item : _lyricSet) {
      auto child = self.append_child("lyric");
      item->ostream(child);
    }
    if(_playSet.size()>0 || _hasPlayId) {
      auto node = self.append_child("play");
      if(_hasPlayId) {
        node.append_attribute("id").set_value(_playId.c_str());
      }
      for(auto item : _playSet) {
        if(std::dynamic_pointer_cast<Ipa>(item).get()) {
          auto child = node.append_child("ipa");
          item->ostream(child);
        }else if(std::dynamic_pointer_cast<Mute>(item).get()) {
          auto child = node.append_child("mute");
          item->ostream(child);
        }else if(std::dynamic_pointer_cast<SemiPitched>(item).get()) {
          auto child = node.append_child("semi-pitched");
          item->ostream(child);
        }else if(std::dynamic_pointer_cast<OtherPlay>(item).get()) {
          auto child = node.append_child("other-play");
          item->ostream(child);
        }
      }
    }
  }
  void Note::istreamContents(const pugi::xml_node& self)
  {
    if(self.children().begin()==self.children().end()) return;
    auto begin = *(self.children().begin());
    if(strcmp(begin.name(), "grace")==0) {
      for(auto child: self.children()) {
        if(strcmp(child.name(), "grace")==0) {
          auto gracePtr = std::make_shared<Grace>();
          gracePtr->istream(child);
          setGrace(gracePtr);
        }
        else if(strcmp(child.name(), "chord")==0) {
          auto chordPtr = std::make_shared<Chord>();
          chordPtr->istream(child);
          setChord(chordPtr);
        }
        else if(strcmp(child.name(), "pitch")==0) {
          auto pitchPtr = std::make_shared<Pitch>();
          pitchPtr->istream(child);
          setPitch(pitchPtr);
        }
        else if(strcmp(child.name(), "unpitched")==0) {
          auto unpitchedPtr = std::make_shared<Unpitched>();
          unpitchedPtr->istream(child);
          setUnpitched(unpitchedPtr);
        }
        else if(strcmp(child.name(), "rest")==0) {
          auto restPtr = std::make_shared<Rest>();
          restPtr->istream(child);
          setRest(restPtr);
        }
        else if(strcmp(child.name(), "tie")==0) {
          auto tiePtr = std::make_shared<Tie>();
          tiePtr->istream(child);
          addTie(tiePtr);
        }
        else if(strcmp(child.name(), "instrument")==0) {
          auto instrumentPtr = std::make_shared<Instrument>();
          instrumentPtr->istream(child);
          setInstrument(instrumentPtr);
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
        else if(strcmp(child.name(), "type")==0) {
          auto typePtr = std::make_shared<Type>();
          typePtr->istream(child);
          setType(typePtr);
        }
        else if(strcmp(child.name(), "dot")==0) {
          auto dotPtr = std::make_shared<Dot>();
          dotPtr->istream(child);
          addDot(dotPtr);
        }
        else if(strcmp(child.name(), "accidental")==0) {
          auto accidentalPtr = std::make_shared<Accidental>();
          accidentalPtr->istream(child);
          setAccidental(accidentalPtr);
        }
        else if(strcmp(child.name(), "time-modification")==0) {
          auto timeModificationPtr = std::make_shared<TimeModification>();
          timeModificationPtr->istream(child);
          setTimeModification(timeModificationPtr);
        }
        else if(strcmp(child.name(), "stem")==0) {
          auto stemPtr = std::make_shared<Stem>();
          stemPtr->istream(child);
          setStem(stemPtr);
        }
        else if(strcmp(child.name(), "notehead")==0) {
          auto noteheadPtr = std::make_shared<Notehead>();
          noteheadPtr->istream(child);
          setNotehead(noteheadPtr);
        }
        else if(strcmp(child.name(), "notehead-text")==0) {
          auto noteheadTextPtr = std::make_shared<NoteheadText>();
          noteheadTextPtr->istream(child);
          setNoteheadText(noteheadTextPtr);
        }
        else if(strcmp(child.name(), "staff")==0) {
          auto staffPtr = std::make_shared<Staff>();
          staffPtr->istream(child);
          setStaff(staffPtr);
        }
        else if(strcmp(child.name(), "beam")==0) {
          auto beamPtr = std::make_shared<Beam>();
          beamPtr->istream(child);
          addBeam(beamPtr);
        }
        else if(strcmp(child.name(), "notations")==0) {
          auto notationsPtr = std::make_shared<Notations>();
          notationsPtr->istream(child);
          addNotations(notationsPtr);
        }
        else if(strcmp(child.name(), "lyric")==0) {
          auto lyricPtr = std::make_shared<Lyric>();
          lyricPtr->istream(child);
          addLyric(lyricPtr);
        }
        else if(strcmp(child.name(), "play")==0) {
          if(auto attr = child.attribute("id")) {
            _playId = attr.as_string();
            _hasPlayId = true;
          }
          for(auto node: child.children()) {
            if(strcmp(node.name(), "ipa")==0) {
              auto item = std::make_shared<Ipa>();
              item->istream(node);
              addPlay(item);
            }else if(strcmp(node.name(), "mute")==0) {
              auto item = std::make_shared<Mute>();
              item->istream(node);
              addPlay(item);
            }else if(strcmp(node.name(), "semi-pitched")==0) {
              auto item = std::make_shared<SemiPitched>();
              item->istream(node);
              addPlay(item);
            }else if(strcmp(node.name(), "other-play")==0) {
              auto item = std::make_shared<OtherPlay>();
              item->istream(node);
              addPlay(item);
            }
          }
        }
      }
    }
    else if(strcmp(begin.name(), "cue")==0) {
      for(auto child: self.children()) {
        if(strcmp(child.name(), "cue")==0) {
          auto cuePtr = std::make_shared<Cue>();
          cuePtr->istream(child);
          setCue(cuePtr);
        }
        else if(strcmp(child.name(), "chord")==0) {
          auto chordPtr = std::make_shared<Chord>();
          chordPtr->istream(child);
          setChord(chordPtr);
        }
        else if(strcmp(child.name(), "pitch")==0) {
          auto pitchPtr = std::make_shared<Pitch>();
          pitchPtr->istream(child);
          setPitch(pitchPtr);
        }
        else if(strcmp(child.name(), "unpitched")==0) {
          auto unpitchedPtr = std::make_shared<Unpitched>();
          unpitchedPtr->istream(child);
          setUnpitched(unpitchedPtr);
        }
        else if(strcmp(child.name(), "rest")==0) {
          auto restPtr = std::make_shared<Rest>();
          restPtr->istream(child);
          setRest(restPtr);
        }
        else if(strcmp(child.name(), "duration")==0) {
          auto durationPtr = std::make_shared<Duration>();
          durationPtr->istream(child);
          setDuration(durationPtr);
        }
        else if(strcmp(child.name(), "instrument")==0) {
          auto instrumentPtr = std::make_shared<Instrument>();
          instrumentPtr->istream(child);
          setInstrument(instrumentPtr);
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
        else if(strcmp(child.name(), "type")==0) {
          auto typePtr = std::make_shared<Type>();
          typePtr->istream(child);
          setType(typePtr);
        }
        else if(strcmp(child.name(), "dot")==0) {
          auto dotPtr = std::make_shared<Dot>();
          dotPtr->istream(child);
          addDot(dotPtr);
        }
        else if(strcmp(child.name(), "accidental")==0) {
          auto accidentalPtr = std::make_shared<Accidental>();
          accidentalPtr->istream(child);
          setAccidental(accidentalPtr);
        }
        else if(strcmp(child.name(), "time-modification")==0) {
          auto timeModificationPtr = std::make_shared<TimeModification>();
          timeModificationPtr->istream(child);
          setTimeModification(timeModificationPtr);
        }
        else if(strcmp(child.name(), "stem")==0) {
          auto stemPtr = std::make_shared<Stem>();
          stemPtr->istream(child);
          setStem(stemPtr);
        }
        else if(strcmp(child.name(), "notehead")==0) {
          auto noteheadPtr = std::make_shared<Notehead>();
          noteheadPtr->istream(child);
          setNotehead(noteheadPtr);
        }
        else if(strcmp(child.name(), "notehead-text")==0) {
          auto noteheadTextPtr = std::make_shared<NoteheadText>();
          noteheadTextPtr->istream(child);
          setNoteheadText(noteheadTextPtr);
        }
        else if(strcmp(child.name(), "staff")==0) {
          auto staffPtr = std::make_shared<Staff>();
          staffPtr->istream(child);
          setStaff(staffPtr);
        }
        else if(strcmp(child.name(), "beam")==0) {
          auto beamPtr = std::make_shared<Beam>();
          beamPtr->istream(child);
          addBeam(beamPtr);
        }
        else if(strcmp(child.name(), "notations")==0) {
          auto notationsPtr = std::make_shared<Notations>();
          notationsPtr->istream(child);
          addNotations(notationsPtr);
        }
        else if(strcmp(child.name(), "lyric")==0) {
          auto lyricPtr = std::make_shared<Lyric>();
          lyricPtr->istream(child);
          addLyric(lyricPtr);
        }
        else if(strcmp(child.name(), "play")==0) {
          if(auto attr = child.attribute("id")) {
            _playId = attr.as_string();
            _hasPlayId = true;
          }
          for(auto node: child.children()) {
            if(strcmp(node.name(), "ipa")==0) {
              auto item = std::make_shared<Ipa>();
              item->istream(node);
              addPlay(item);
            }else if(strcmp(node.name(), "mute")==0) {
              auto item = std::make_shared<Mute>();
              item->istream(node);
              addPlay(item);
            }else if(strcmp(node.name(), "semi-pitched")==0) {
              auto item = std::make_shared<SemiPitched>();
              item->istream(node);
              addPlay(item);
            }else if(strcmp(node.name(), "other-play")==0) {
              auto item = std::make_shared<OtherPlay>();
              item->istream(node);
              addPlay(item);
            }
          }
        }
      }
    }
    else {
      for(auto child: self.children()) {
        if(strcmp(child.name(), "chord")==0) {
          auto chordPtr = std::make_shared<Chord>();
          chordPtr->istream(child);
          setChord(chordPtr);
        }
        else if(strcmp(child.name(), "pitch")==0) {
          auto pitchPtr = std::make_shared<Pitch>();
          pitchPtr->istream(child);
          setPitch(pitchPtr);
        }
        else if(strcmp(child.name(), "unpitched")==0) {
          auto unpitchedPtr = std::make_shared<Unpitched>();
          unpitchedPtr->istream(child);
          setUnpitched(unpitchedPtr);
        }
        else if(strcmp(child.name(), "rest")==0) {
          auto restPtr = std::make_shared<Rest>();
          restPtr->istream(child);
          setRest(restPtr);
        }
        else if(strcmp(child.name(), "duration")==0) {
          auto durationPtr = std::make_shared<Duration>();
          durationPtr->istream(child);
          setDuration(durationPtr);
        }
        else if(strcmp(child.name(), "tie")==0) {
          auto tiePtr = std::make_shared<Tie>();
          tiePtr->istream(child);
          addTie(tiePtr);
        }
        else if(strcmp(child.name(), "instrument")==0) {
          auto instrumentPtr = std::make_shared<Instrument>();
          instrumentPtr->istream(child);
          setInstrument(instrumentPtr);
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
        else if(strcmp(child.name(), "type")==0) {
          auto typePtr = std::make_shared<Type>();
          typePtr->istream(child);
          setType(typePtr);
        }
        else if(strcmp(child.name(), "dot")==0) {
          auto dotPtr = std::make_shared<Dot>();
          dotPtr->istream(child);
          addDot(dotPtr);
        }
        else if(strcmp(child.name(), "accidental")==0) {
          auto accidentalPtr = std::make_shared<Accidental>();
          accidentalPtr->istream(child);
          setAccidental(accidentalPtr);
        }
        else if(strcmp(child.name(), "time-modification")==0) {
          auto timeModificationPtr = std::make_shared<TimeModification>();
          timeModificationPtr->istream(child);
          setTimeModification(timeModificationPtr);
        }
        else if(strcmp(child.name(), "stem")==0) {
          auto stemPtr = std::make_shared<Stem>();
          stemPtr->istream(child);
          setStem(stemPtr);
        }
        else if(strcmp(child.name(), "notehead")==0) {
          auto noteheadPtr = std::make_shared<Notehead>();
          noteheadPtr->istream(child);
          setNotehead(noteheadPtr);
        }
        else if(strcmp(child.name(), "notehead-text")==0) {
          auto noteheadTextPtr = std::make_shared<NoteheadText>();
          noteheadTextPtr->istream(child);
          setNoteheadText(noteheadTextPtr);
        }
        else if(strcmp(child.name(), "staff")==0) {
          auto staffPtr = std::make_shared<Staff>();
          staffPtr->istream(child);
          setStaff(staffPtr);
        }
        else if(strcmp(child.name(), "beam")==0) {
          auto beamPtr = std::make_shared<Beam>();
          beamPtr->istream(child);
          addBeam(beamPtr);
        }
        else if(strcmp(child.name(), "notations")==0) {
          auto notationsPtr = std::make_shared<Notations>();
          notationsPtr->istream(child);
          addNotations(notationsPtr);
        }
        else if(strcmp(child.name(), "lyric")==0) {
          auto lyricPtr = std::make_shared<Lyric>();
          lyricPtr->istream(child);
          addLyric(lyricPtr);
        }
        else if(strcmp(child.name(), "play")==0) {
          if(auto attr = child.attribute("id")) {
            _playId = attr.as_string();
            _hasPlayId = true;
          }
          for(auto node: child.children()) {
            if(strcmp(node.name(), "ipa")==0) {
              auto item = std::make_shared<Ipa>();
              item->istream(node);
              addPlay(item);
            }else if(strcmp(node.name(), "mute")==0) {
              auto item = std::make_shared<Mute>();
              item->istream(node);
              addPlay(item);
            }else if(strcmp(node.name(), "semi-pitched")==0) {
              auto item = std::make_shared<SemiPitched>();
              item->istream(node);
              addPlay(item);
            }else if(strcmp(node.name(), "other-play")==0) {
              auto item = std::make_shared<OtherPlay>();
              item->istream(node);
              addPlay(item);
            }
          }
        }
      }
    }
  }
}
