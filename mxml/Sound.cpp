#include "Sound.h"
#include <cstring>
#include "MidiInfo.h"
#include "MidiDevice.h"
#include "MidiInstrument.h"
#include "Ipa.h"
#include "Mute.h"
#include "SemiPitched.h"
#include "OtherPlay.h"
#include "Offset.h"

namespace mxml
{
  Sound::Sound() {}
  const MidiInfoSet& Sound::getMidiInfoSet() const {  return _midiInfoSet; }
  void Sound::removeMidiInfo(const MidiInfoPtr& value) { if(value) { auto i = std::find_if(_midiInfoSet.begin(), _midiInfoSet.end(), [&](const MidiInfoPtr& item) { return item==value; }); if(i!=_midiInfoSet.end()) _midiInfoSet.erase(i); } } 
  void Sound::addMidiInfo(const MidiInfoPtr& value) { if(value) { _midiInfoSet.push_back(value); value->setParent(shared_from_this()); } }
  void Sound::clearMidiInfoSet() { _midiInfoSet.clear(); }
  OffsetPtr Sound::getOffset() const { return _offsetPtr; }
  void Sound::setOffset(const OffsetPtr& value) { _offsetPtr = value; value->setParent(shared_from_this()); }
  bool Sound::hasTempo() const { return _hasTempo; }
  void Sound::hasTempo(bool value) { _hasTempo = value; }
  float Sound::tempo() const { return _tempo; }
  void Sound::tempo(float value) { _tempo = value; }
  bool Sound::hasDynamics() const { return _hasDynamics; }
  void Sound::hasDynamics(bool value) { _hasDynamics = value; }
  float Sound::dynamics() const { return _dynamics; }
  void Sound::dynamics(float value) { _dynamics = value; }
  bool Sound::hasDacapo() const { return _hasDacapo; }
  void Sound::hasDacapo(bool value) { _hasDacapo = value; }
  YesNoEnum Sound::dacapo() const { return _dacapo; }
  void Sound::dacapo(YesNoEnum value) { _dacapo = value; }
  bool Sound::hasSegno() const { return _hasSegno; }
  void Sound::hasSegno(bool value) { _hasSegno = value; }
  std::string Sound::segno() const { return _segno; }
  void Sound::segno(std::string value) { _segno = value; }
  bool Sound::hasDalsegno() const { return _hasDalsegno; }
  void Sound::hasDalsegno(bool value) { _hasDalsegno = value; }
  std::string Sound::dalsegno() const { return _dalsegno; }
  void Sound::dalsegno(std::string value) { _dalsegno = value; }
  bool Sound::hasCoda() const { return _hasCoda; }
  void Sound::hasCoda(bool value) { _hasCoda = value; }
  std::string Sound::coda() const { return _coda; }
  void Sound::coda(std::string value) { _coda = value; }
  bool Sound::hasTocoda() const { return _hasTocoda; }
  void Sound::hasTocoda(bool value) { _hasTocoda = value; }
  std::string Sound::tocoda() const { return _tocoda; }
  void Sound::tocoda(std::string value) { _tocoda = value; }
  bool Sound::hasDivisions() const { return _hasDivisions; }
  void Sound::hasDivisions(bool value) { _hasDivisions = value; }
  float Sound::divisions() const { return _divisions; }
  void Sound::divisions(float value) { _divisions = value; }
  bool Sound::hasForwardRepeat() const { return _hasForwardRepeat; }
  void Sound::hasForwardRepeat(bool value) { _hasForwardRepeat = value; }
  YesNoEnum Sound::forwardRepeat() const { return _forwardRepeat; }
  void Sound::forwardRepeat(YesNoEnum value) { _forwardRepeat = value; }
  bool Sound::hasFine() const { return _hasFine; }
  void Sound::hasFine(bool value) { _hasFine = value; }
  std::string Sound::fine() const { return _fine; }
  void Sound::fine(std::string value) { _fine = value; }
  bool Sound::hasTimeOnly() const { return _hasTimeOnly; }
  void Sound::hasTimeOnly(bool value) { _hasTimeOnly = value; }
  std::string Sound::timeOnly() const { return _timeOnly; }
  void Sound::timeOnly(std::string value) { _timeOnly = value; }
  bool Sound::hasPizzicato() const { return _hasPizzicato; }
  void Sound::hasPizzicato(bool value) { _hasPizzicato = value; }
  YesNoEnum Sound::pizzicato() const { return _pizzicato; }
  void Sound::pizzicato(YesNoEnum value) { _pizzicato = value; }
  bool Sound::hasPan() const { return _hasPan; }
  void Sound::hasPan(bool value) { _hasPan = value; }
  float Sound::pan() const { return _pan; }
  void Sound::pan(float value) { _pan = value; }
  bool Sound::hasElevation() const { return _hasElevation; }
  void Sound::hasElevation(bool value) { _hasElevation = value; }
  float Sound::elevation() const { return _elevation; }
  void Sound::elevation(float value) { _elevation = value; }
  bool Sound::hasDamperPedal() const { return _hasDamperPedal; }
  void Sound::hasDamperPedal(bool value) { _hasDamperPedal = value; }
  YesNoNumberEnum Sound::damperPedal() const { return _damperPedal; }
  void Sound::damperPedal(YesNoNumberEnum value) { _damperPedal = value; }
  bool Sound::hasSoftPedal() const { return _hasSoftPedal; }
  void Sound::hasSoftPedal(bool value) { _hasSoftPedal = value; }
  YesNoNumberEnum Sound::softPedal() const { return _softPedal; }
  void Sound::softPedal(YesNoNumberEnum value) { _softPedal = value; }
  bool Sound::hasSostenutoPedal() const { return _hasSostenutoPedal; }
  void Sound::hasSostenutoPedal(bool value) { _hasSostenutoPedal = value; }
  YesNoNumberEnum Sound::sostenutoPedal() const { return _sostenutoPedal; }
  void Sound::sostenutoPedal(YesNoNumberEnum value) { _sostenutoPedal = value; }

  void Sound::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasTempo) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _tempo);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("tempo").set_value(str);
    }
    if(_hasDynamics) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _dynamics);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("dynamics").set_value(str);
    }
    if(_hasDacapo) {
      self.append_attribute("dacapo").set_value(_dacapo.operator const char *());
    }
    if(_hasSegno) {
      self.append_attribute("segno").set_value(_segno.c_str());
    }
    if(_hasDalsegno) {
      self.append_attribute("dalsegno").set_value(_dalsegno.c_str());
    }
    if(_hasCoda) {
      self.append_attribute("coda").set_value(_coda.c_str());
    }
    if(_hasTocoda) {
      self.append_attribute("tocoda").set_value(_tocoda.c_str());
    }
    if(_hasDivisions) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _divisions);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("divisions").set_value(str);
    }
    if(_hasForwardRepeat) {
      self.append_attribute("forward-repeat").set_value(_forwardRepeat.operator const char *());
    }
    if(_hasFine) {
      self.append_attribute("fine").set_value(_fine.c_str());
    }
    if(_hasTimeOnly) {
      self.append_attribute("time-only").set_value(_timeOnly.c_str());
    }
    if(_hasPizzicato) {
      self.append_attribute("pizzicato").set_value(_pizzicato.operator const char *());
    }
    if(_hasPan) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _pan);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("pan").set_value(str);
    }
    if(_hasElevation) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _elevation);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("elevation").set_value(str);
    }
    if(_hasDamperPedal) {
      self.append_attribute("damper-pedal").set_value(_damperPedal.operator const char *());
    }
    if(_hasSoftPedal) {
      self.append_attribute("soft-pedal").set_value(_softPedal.operator const char *());
    }
    if(_hasSostenutoPedal) {
      self.append_attribute("sostenuto-pedal").set_value(_sostenutoPedal.operator const char *());
    }
  }
  void Sound::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("tempo")) {
      _tempo = attr.as_float();
      _hasTempo = true;
    }
    if(auto attr = self.attribute("dynamics")) {
      _dynamics = attr.as_float();
      _hasDynamics = true;
    }
    if(auto attr = self.attribute("dacapo")) {
      _dacapo = YesNoEnum(attr.as_string());
      _hasDacapo = true;
    }
    if(auto attr = self.attribute("segno")) {
      _segno = attr.as_string();
      _hasSegno = true;
    }
    if(auto attr = self.attribute("dalsegno")) {
      _dalsegno = attr.as_string();
      _hasDalsegno = true;
    }
    if(auto attr = self.attribute("coda")) {
      _coda = attr.as_string();
      _hasCoda = true;
    }
    if(auto attr = self.attribute("tocoda")) {
      _tocoda = attr.as_string();
      _hasTocoda = true;
    }
    if(auto attr = self.attribute("divisions")) {
      _divisions = attr.as_float();
      _hasDivisions = true;
    }
    if(auto attr = self.attribute("forward-repeat")) {
      _forwardRepeat = YesNoEnum(attr.as_string());
      _hasForwardRepeat = true;
    }
    if(auto attr = self.attribute("fine")) {
      _fine = attr.as_string();
      _hasFine = true;
    }
    if(auto attr = self.attribute("time-only")) {
      _timeOnly = attr.as_string();
      _hasTimeOnly = true;
    }
    if(auto attr = self.attribute("pizzicato")) {
      _pizzicato = YesNoEnum(attr.as_string());
      _hasPizzicato = true;
    }
    if(auto attr = self.attribute("pan")) {
      _pan = attr.as_float();
      _hasPan = true;
    }
    if(auto attr = self.attribute("elevation")) {
      _elevation = attr.as_float();
      _hasElevation = true;
    }
    if(auto attr = self.attribute("damper-pedal")) {
      _damperPedal = YesNoNumberEnum(attr.as_string());
      _hasDamperPedal = true;
    }
    if(auto attr = self.attribute("soft-pedal")) {
      _softPedal = YesNoNumberEnum(attr.as_string());
      _hasSoftPedal = true;
    }
    if(auto attr = self.attribute("sostenuto-pedal")) {
      _sostenutoPedal = YesNoNumberEnum(attr.as_string());
      _hasSostenutoPedal = true;
    }
  }
  void Sound::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _midiInfoSet) {
      item->ostream(self);
    }
    if(_offsetPtr) {
      auto child = self.append_child("offset");
      _offsetPtr->ostream(child);
    }
  }
  void Sound::istreamContents(const pugi::xml_node& self)
  {
    MidiInfoPtr midiInfoPtr;
    for(auto child: self.children()) {
      if(strcmp(child.name(), "midi-device")==0) {
        auto midiDevicePtr = std::make_shared<MidiDevice>();
        midiDevicePtr->istream(child);
        midiInfoPtr = std::make_shared<MidiInfo>();
        midiInfoPtr->setMidiDevice(midiDevicePtr);
        addMidiInfo(midiInfoPtr);
      }
      else if(strcmp(child.name(), "midi-instrument")==0) {
        if(midiInfoPtr) {
          auto midiInstrumentPtr = std::make_shared<MidiInstrument>();
          midiInstrumentPtr->istream(child);
          midiInfoPtr->setMidiInstrument(midiInstrumentPtr);
        }  
      }
      else if(strcmp(child.name(), "play")==0) {
        if(midiInfoPtr) {
          if(auto attr = child.attribute("id")) {
            midiInfoPtr->playId(attr.as_string());
            midiInfoPtr->hasPlayId(true);
          }
          for(auto node: child.children()) {
            if(strcmp(node.name(), "ipa")==0) {
              auto item = std::make_shared<Ipa>();
              item->istream(node);
              midiInfoPtr->addPlay(item);
            }else if(strcmp(node.name(), "mute")==0) {
              auto item = std::make_shared<Mute>();
              item->istream(node);
              midiInfoPtr->addPlay(item);
            }else if(strcmp(node.name(), "semi-pitched")==0) {
              auto item = std::make_shared<SemiPitched>();
              item->istream(node);
              midiInfoPtr->addPlay(item);
            }else if(strcmp(node.name(), "other-play")==0) {
              auto item = std::make_shared<OtherPlay>();
              item->istream(node);
              midiInfoPtr->addPlay(item);
            }
          }
        }  
      }
      else if(strcmp(child.name(), "offset")==0) {
        auto offsetPtr = std::make_shared<Offset>();
        setOffset(offsetPtr);
      }
    }
  }
}
