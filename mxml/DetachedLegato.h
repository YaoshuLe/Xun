#ifndef DETACHED_LEGATO_H
#define DETACHED_LEGATO_H
#include "EmptyPlacement.h"

namespace mxml
{
  class DetachedLegato: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "detached-legato"; }
  };
}
#endif //DETACHED_LEGATO_H
