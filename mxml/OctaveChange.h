#ifndef OCTAVE_CHANGE_H
#define OCTAVE_CHANGE_H
#include "Element.h"

namespace mxml
{
  class OctaveChange: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "octave-change"; }
  };
}
#endif //OCTAVE_CHANGE_H
