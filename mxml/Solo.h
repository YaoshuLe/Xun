#ifndef SOLO_H
#define SOLO_H
#include "Element.h"

namespace mxml
{
  class Solo: public Empty
  {
  public:
    virtual const char* tagname() const { return "solo"; }
  };
}
#endif //SOLO_H
