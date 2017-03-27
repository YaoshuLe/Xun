#ifndef MIDI_INSTRUMENT_H
#define MIDI_INSTRUMENT_H
#include "Element.h"

namespace mxml
{
  class MidiChannel;
  using MidiChannelPtr = std::shared_ptr<MidiChannel>;
  class MidiName;
  using MidiNamePtr = std::shared_ptr<MidiName>;
  class MidiBank;
  using MidiBankPtr = std::shared_ptr<MidiBank>;
  class MidiProgram;
  using MidiProgramPtr = std::shared_ptr<MidiProgram>;
  class MidiUnpitched;
  using MidiUnpitchedPtr = std::shared_ptr<MidiUnpitched>;
  class Volume;
  using VolumePtr = std::shared_ptr<Volume>;
  class Pan;
  using PanPtr = std::shared_ptr<Pan>;
  class Elevation;
  using ElevationPtr = std::shared_ptr<Elevation>;

  class MidiInstrument: public Element
  {
  public:
    MidiInstrument();
    virtual const char* tagname() const { return "midi-instrument"; }
    MidiChannelPtr getMidiChannel() const;
    void setMidiChannel(const MidiChannelPtr& value);
    MidiNamePtr getMidiName() const;
    void setMidiName(const MidiNamePtr& value);
    MidiBankPtr getMidiBank() const;
    void setMidiBank(const MidiBankPtr& value);
    MidiProgramPtr getMidiProgram() const;
    void setMidiProgram(const MidiProgramPtr& value);
    MidiUnpitchedPtr getMidiUnpitched() const;
    void setMidiUnpitched(const MidiUnpitchedPtr& value);
    VolumePtr getVolume() const;
    void setVolume(const VolumePtr& value);
    PanPtr getPan() const;
    void setPan(const PanPtr& value);
    ElevationPtr getElevation() const;
    void setElevation(const ElevationPtr& value);
    bool hasId() const;
    void hasId(bool value);
    std::string id() const;
    void id(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    MidiChannelPtr _midiChannelPtr;
    MidiNamePtr _midiNamePtr;
    MidiBankPtr _midiBankPtr;
    MidiProgramPtr _midiProgramPtr;
    MidiUnpitchedPtr _midiUnpitchedPtr;
    VolumePtr _volumePtr;
    PanPtr _panPtr;
    ElevationPtr _elevationPtr;
    bool _hasId {false};
    std::string _id;
  };
}
#endif //MIDI_INSTRUMENT_H
