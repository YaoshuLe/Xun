#ifndef METRONOME_TYPE_H
#define METRONOME_TYPE_H
#include "Element.h"

namespace mxml
{
  class MetronomeType: public Value<NoteTypeValueEnum>
  {
  public:
    virtual const char* tagname() const { return "metronome-type"; }
  };
}
#endif //METRONOME_TYPE_H
