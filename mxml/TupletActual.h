#ifndef TUPLET_ACTUAL_H
#define TUPLET_ACTUAL_H
#include "TupletPortion.h"

namespace mxml
{
  class TupletActual: public TupletPortion
  {
  public:
    virtual const char* tagname() const { return "tuplet-actual"; }
  };
}
#endif //TUPLET_ACTUAL_H
