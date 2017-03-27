#ifndef BEAT_UNIT_H
#define BEAT_UNIT_H
#include "Element.h"

namespace mxml
{
  class BeatUnit: public Value<NoteTypeValueEnum>
  {
  public:
    virtual const char* tagname() const { return "beat-unit"; }
  };
}
#endif //BEAT_UNIT_H
