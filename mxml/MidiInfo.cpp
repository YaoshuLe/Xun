#include "MidiInfo.h"
#include <cstring>
#include "MidiDevice.h"
#include "MidiInstrument.h"
#include "Ipa.h"
#include "Mute.h"
#include "SemiPitched.h"
#include "OtherPlay.h"

namespace mxml
{
  MidiInfo::MidiInfo() {}
  MidiDevicePtr MidiInfo::getMidiDevice() const { return _midiDevicePtr; }
  void MidiInfo::setMidiDevice(const MidiDevicePtr& value) { _midiDevicePtr = value; value->setParent(shared_from_this()); }
  MidiInstrumentPtr MidiInfo::getMidiInstrument() const { return _midiInstrumentPtr; }
  void MidiInfo::setMidiInstrument(const MidiInstrumentPtr& value) { _midiInstrumentPtr = value; value->setParent(shared_from_this()); }
  const PlaySet& MidiInfo::getPlaySet() const {  return _playSet; }
  void MidiInfo::removePlay(const PlayPtr& value) { if(value) { auto i = std::find_if(_playSet.begin(), _playSet.end(), [&](const PlayPtr& item) { return item==value; }); if(i!=_playSet.end()) _playSet.erase(i); } }
  void MidiInfo::addPlay(const PlayPtr& value) { if(value) { _playSet.push_back(value); value->setParent(shared_from_this()); } }
  void MidiInfo::clearPlaySet() { _playSet.clear(); }
  bool MidiInfo::hasPlayId() const { return _hasPlayId; }
  void MidiInfo::hasPlayId(bool value) { _hasPlayId = value; }
  std::string MidiInfo::playId() const { return _playId; }
  void MidiInfo::playId(std::string value) { _playId = value; }

  void MidiInfo::ostreamContents(pugi::xml_node& self) const
  {
    if(_midiDevicePtr) {
      auto child = self.append_child("midi-device");
      _midiDevicePtr->ostream(child);
    }
    if(_midiInstrumentPtr) {
      auto child = self.append_child("midi-instrument");
      _midiInstrumentPtr->ostream(child);
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
  void MidiInfo::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "midi-device")==0) {
        auto midiDevicePtr = std::make_shared<MidiDevice>();
        midiDevicePtr->istream(child);
        setMidiDevice(midiDevicePtr);
      }
      else if(strcmp(child.name(), "midi-instrument")==0) {
        auto midiInstrumentPtr = std::make_shared<MidiInstrument>();
        midiInstrumentPtr->istream(child);
        setMidiInstrument(midiInstrumentPtr);
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
