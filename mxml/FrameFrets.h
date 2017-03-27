#ifndef FRAME_FRETS_H
#define FRAME_FRETS_H
#include "Element.h"

namespace mxml
{
  class FrameFrets: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "frame-frets"; }
  };
}
#endif //FRAME_FRETS_H
