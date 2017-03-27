#ifndef DISPLAY_OCTAVE_H
#define DISPLAY_OCTAVE_H
#include "Element.h"

namespace mxml
{
  class DisplayOctave: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "display-octave"; }
  };
}
#endif //DISPLAY_OCTAVE_H
