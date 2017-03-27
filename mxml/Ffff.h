#ifndef FFFF_H
#define FFFF_H
#include "Element.h"

namespace mxml
{
  class Ffff: public Empty
  {
  public:
    virtual const char* tagname() const { return "ffff"; }
  };
}
#endif //FFFF_H
