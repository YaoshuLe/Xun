#ifndef CAPO_H
#define CAPO_H
#include "Element.h"

namespace mxml
{
  class Capo: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "capo"; }
  };
}
#endif //CAPO_H
