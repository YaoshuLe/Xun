#include "MidiInstrument.h"
#include <cstring>
#include "MidiChannel.h"
#include "MidiName.h"
#include "MidiBank.h"
#include "MidiProgram.h"
#include "MidiUnpitched.h"
#include "Volume.h"
#include "Pan.h"
#include "Elevation.h"

namespace mxml
{
  MidiInstrument::MidiInstrument() {}
  MidiChannelPtr MidiInstrument::getMidiChannel() const { return _midiChannelPtr; }
  void MidiInstrument::setMidiChannel(const MidiChannelPtr& value) { _midiChannelPtr = value; value->setParent(shared_from_this()); }
  MidiNamePtr MidiInstrument::getMidiName() const { return _midiNamePtr; }
  void MidiInstrument::setMidiName(const MidiNamePtr& value) { _midiNamePtr = value; value->setParent(shared_from_this()); }
  MidiBankPtr MidiInstrument::getMidiBank() const { return _midiBankPtr; }
  void MidiInstrument::setMidiBank(const MidiBankPtr& value) { _midiBankPtr = value; value->setParent(shared_from_this()); }
  MidiProgramPtr MidiInstrument::getMidiProgram() const { return _midiProgramPtr; }
  void MidiInstrument::setMidiProgram(const MidiProgramPtr& value) { _midiProgramPtr = value; value->setParent(shared_from_this()); }
  MidiUnpitchedPtr MidiInstrument::getMidiUnpitched() const { return _midiUnpitchedPtr; }
  void MidiInstrument::setMidiUnpitched(const MidiUnpitchedPtr& value) { _midiUnpitchedPtr = value; value->setParent(shared_from_this()); }
  VolumePtr MidiInstrument::getVolume() const { return _volumePtr; }
  void MidiInstrument::setVolume(const VolumePtr& value) { _volumePtr = value; value->setParent(shared_from_this()); }
  PanPtr MidiInstrument::getPan() const { return _panPtr; }
  void MidiInstrument::setPan(const PanPtr& value) { _panPtr = value; value->setParent(shared_from_this()); }
  ElevationPtr MidiInstrument::getElevation() const { return _elevationPtr; }
  void MidiInstrument::setElevation(const ElevationPtr& value) { _elevationPtr = value; value->setParent(shared_from_this()); }
  bool MidiInstrument::hasId() const { return _hasId; }
  void MidiInstrument::hasId(bool value) { _hasId = value; }
  std::string MidiInstrument::id() const { return _id; }
  void MidiInstrument::id(std::string value) { _id = value; }

  void MidiInstrument::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasId) {
      self.append_attribute("id").set_value(_id.c_str());
    }
  }
  void MidiInstrument::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("id")) {
      _id = attr.as_string();
      _hasId = true;
    }
  }
  void MidiInstrument::ostreamContents(pugi::xml_node& self) const
  {
    if(_midiChannelPtr) {
      auto child = self.append_child("midi-channel");
      _midiChannelPtr->ostream(child);
    }
    if(_midiNamePtr) {
      auto child = self.append_child("midi-name");
      _midiNamePtr->ostream(child);
    }
    if(_midiBankPtr) {
      auto child = self.append_child("midi-bank");
      _midiBankPtr->ostream(child);
    }
    if(_midiProgramPtr) {
      auto child = self.append_child("midi-program");
      _midiProgramPtr->ostream(child);
    }
    if(_midiUnpitchedPtr) {
      auto child = self.append_child("midi-unpitched");
      _midiUnpitchedPtr->ostream(child);
    }
    if(_volumePtr) {
      auto child = self.append_child("volume");
      _volumePtr->ostream(child);
    }
    if(_panPtr) {
      auto child = self.append_child("pan");
      _panPtr->ostream(child);
    }
    if(_elevationPtr) {
      auto child = self.append_child("elevation");
      _elevationPtr->ostream(child);
    }
  }
  void MidiInstrument::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "midi-channel")==0) {
        auto midiChannelPtr = std::make_shared<MidiChannel>();
        midiChannelPtr->istream(child);
        setMidiChannel(midiChannelPtr);
      }
      else if(strcmp(child.name(), "midi-name")==0) {
        auto midiNamePtr = std::make_shared<MidiName>();
        midiNamePtr->istream(child);
        setMidiName(midiNamePtr);
      }
      else if(strcmp(child.name(), "midi-bank")==0) {
        auto midiBankPtr = std::make_shared<MidiBank>();
        midiBankPtr->istream(child);
        setMidiBank(midiBankPtr);
      }
      else if(strcmp(child.name(), "midi-program")==0) {
        auto midiProgramPtr = std::make_shared<MidiProgram>();
        midiProgramPtr->istream(child);
        setMidiProgram(midiProgramPtr);
      }
      else if(strcmp(child.name(), "midi-unpitched")==0) {
        auto midiUnpitchedPtr = std::make_shared<MidiUnpitched>();
        midiUnpitchedPtr->istream(child);
        setMidiUnpitched(midiUnpitchedPtr);
      }
      else if(strcmp(child.name(), "volume")==0) {
        auto volumePtr = std::make_shared<Volume>();
        volumePtr->istream(child);
        setVolume(volumePtr);
      }
      else if(strcmp(child.name(), "pan")==0) {
        auto panPtr = std::make_shared<Pan>();
        panPtr->istream(child);
        setPan(panPtr);
      }
      else if(strcmp(child.name(), "elevation")==0) {
        auto elevationPtr = std::make_shared<Elevation>();
        elevationPtr->istream(child);
        setElevation(elevationPtr);
      }
    }
  }
}
