#ifndef DOUBLE_TONGUE_H
#define DOUBLE_TONGUE_H
#include "EmptyPlacement.h"

namespace mxml
{
  class DoubleTongue: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "double-tongue"; }
  };
}
#endif //DOUBLE_TONGUE_H
