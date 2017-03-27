#ifndef BEAT_UNIT_DOT_H
#define BEAT_UNIT_DOT_H
#include "Element.h"

namespace mxml
{
  class BeatUnitDot: public Empty
  {
  public:
    virtual const char* tagname() const { return "beat-unit-dot"; }
  };
}
#endif //BEAT_UNIT_DOT_H
