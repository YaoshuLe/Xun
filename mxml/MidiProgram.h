#ifndef MIDI_PROGRAM_H
#define MIDI_PROGRAM_H
#include "Element.h"

namespace mxml
{
  class MidiProgram: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "midi-program"; }
  };
}
#endif //MIDI_PROGRAM_H
