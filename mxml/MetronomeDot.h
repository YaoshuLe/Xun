#ifndef METRONOME_DOT_H
#define METRONOME_DOT_H
#include "Element.h"

namespace mxml
{
  class MetronomeDot: public Empty
  {
  public:
    virtual const char* tagname() const { return "metronome-dot"; }
  };
}
#endif //METRONOME_DOT_H
