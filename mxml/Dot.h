#ifndef DOT_H
#define DOT_H
#include "EmptyPlacement.h"

namespace mxml
{
  class Dot: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "dot"; }
  };
}
#endif //DOT_H
