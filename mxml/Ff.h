#ifndef FF_H
#define FF_H
#include "Element.h"

namespace mxml
{
  class Ff: public Empty
  {
  public:
    virtual const char* tagname() const { return "ff"; }
  };
}
#endif //FF_H
