#ifndef MIDI_BANK_H
#define MIDI_BANK_H
#include "Element.h"

namespace mxml
{
  class MidiBank: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "midi-bank"; }
  };
}
#endif //MIDI_BANK_H
