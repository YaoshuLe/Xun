#ifndef TENUTO_H
#define TENUTO_H
#include "EmptyPlacement.h"

namespace mxml
{
  class Tenuto: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "tenuto"; }
  };
}
#endif //TENUTO_H
