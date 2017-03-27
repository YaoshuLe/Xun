#ifndef SF_H
#define SF_H
#include "Element.h"

namespace mxml
{
  class Sf: public Empty
  {
  public:
    virtual const char* tagname() const { return "sf"; }
  };
}
#endif //SF_H
