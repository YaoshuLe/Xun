#ifndef MIDI_NAME_H
#define MIDI_NAME_H
#include "Element.h"

namespace mxml
{
  class MidiName: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "midi-name"; }
  };
}
#endif //MIDI_NAME_H
