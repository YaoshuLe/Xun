#ifndef FRAME_STRINGS_H
#define FRAME_STRINGS_H
#include "Element.h"

namespace mxml
{
  class FrameStrings: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "frame-strings"; }
  };
}
#endif //FRAME_STRINGS_H
