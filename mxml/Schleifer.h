#ifndef SCHLEIFER_H
#define SCHLEIFER_H
#include "EmptyPlacement.h"

namespace mxml
{
  class Schleifer: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "schleifer"; }
  };
}
#endif //SCHLEIFER_H
