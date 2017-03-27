#ifndef BEND_ALTER_H
#define BEND_ALTER_H
#include "Element.h"

namespace mxml
{
  class BendAlter: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "bend-alter"; }
  };
}
#endif //BEND_ALTER_H
