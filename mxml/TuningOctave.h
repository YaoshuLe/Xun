#ifndef TUNING_OCTAVE_H
#define TUNING_OCTAVE_H
#include "Element.h"

namespace mxml
{
  class TuningOctave: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "tuning-octave"; }
  };
}
#endif //TUNING_OCTAVE_H
