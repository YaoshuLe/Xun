#ifndef THUMB_POSITION_H
#define THUMB_POSITION_H
#include "EmptyPlacement.h"

namespace mxml
{
  class ThumbPosition: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "thumb-position"; }
  };
}
#endif //THUMB_POSITION_H
