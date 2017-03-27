#ifndef FFF_H
#define FFF_H
#include "Element.h"

namespace mxml
{
  class Fff: public Empty
  {
  public:
    virtual const char* tagname() const { return "fff"; }
  };
}
#endif //FFF_H
