#ifndef TRILL_MARK_H
#define TRILL_MARK_H
#include "EmptyTrillSound.h"

namespace mxml
{
  class TrillMark: public EmptyTrillSound
  {
  public:
    virtual const char* tagname() const { return "trill-mark"; }
  };
}
#endif //TRILL_MARK_H
