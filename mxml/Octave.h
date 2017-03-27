#ifndef OCTAVE_H
#define OCTAVE_H
#include "Element.h"

namespace mxml
{
  class Octave: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "octave"; }
  };
}
#endif //OCTAVE_H
