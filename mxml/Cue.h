#ifndef CUE_H
#define CUE_H
#include "Element.h"

namespace mxml
{
  class Cue: public Empty
  {
  public:
    virtual const char* tagname() const { return "cue"; }
  };
}
#endif //CUE_H
