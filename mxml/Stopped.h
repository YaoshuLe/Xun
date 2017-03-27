#ifndef STOPPED_H
#define STOPPED_H
#include "EmptyPlacement.h"

namespace mxml
{
  class Stopped: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "stopped"; }
  };
}
#endif //STOPPED_H
