#ifndef MIDI_UNPITCHED_H
#define MIDI_UNPITCHED_H
#include "Element.h"

namespace mxml
{
  class MidiUnpitched: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "midi-unpitched"; }
  };
}
#endif //MIDI_UNPITCHED_H
