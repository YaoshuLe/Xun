#ifndef MIDI_INFO_H
#define MIDI_INFO_H
#include "Element.h"

namespace mxml
{
  class MidiDevice;
  using MidiDevicePtr = std::shared_ptr<MidiDevice>;
  class MidiInstrument;
  using MidiInstrumentPtr = std::shared_ptr<MidiInstrument>;
  using Play = Element;
  using PlayPtr = std::shared_ptr<Play>;
  using PlaySet = std::vector<PlayPtr>;
  
  class MidiInfo: public Element
  {
  public:
    MidiInfo();
    virtual const char* tagname() const { return "midi-info"; }
    MidiDevicePtr getMidiDevice() const;
    void setMidiDevice(const MidiDevicePtr& value);
    MidiInstrumentPtr getMidiInstrument() const;
    void setMidiInstrument(const MidiInstrumentPtr& value);
    const PlaySet& getPlaySet() const;
    void removePlay(const PlayPtr& value);
    void addPlay(const PlayPtr& value);
    void clearPlaySet();
    bool hasPlayId() const;
    void hasPlayId(bool value);
    std::string playId() const;
    void playId(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    MidiDevicePtr _midiDevicePtr;
    MidiInstrumentPtr _midiInstrumentPtr;
    PlaySet _playSet;
    bool _hasPlayId {false};
    std::string _playId;        
  };
}
#endif //MIDI_INFO_H
