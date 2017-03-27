#ifndef MIDI_CHANNEL_H
#define MIDI_CHANNEL_H
#include "Element.h"

namespace mxml
{
  class MidiChannel: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "midi-channel"; }
  };
}
#endif //MIDI_CHANNEL_H
