#ifndef CLEF_OCTAVE_CHANGE_H
#define CLEF_OCTAVE_CHANGE_H
#include "Element.h"

namespace mxml
{
  class ClefOctaveChange: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "clef-octave-change"; }
  };
}
#endif //CLEF_OCTAVE_CHANGE_H
