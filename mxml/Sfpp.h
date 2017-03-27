#ifndef SFPP_H
#define SFPP_H
#include "Element.h"

namespace mxml
{
  class Sfpp: public Empty
  {
  public:
    virtual const char* tagname() const { return "sfpp"; }
  };
}
#endif //SFPP_H
