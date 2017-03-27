#ifndef DIATONIC_H
#define DIATONIC_H
#include "Element.h"

namespace mxml
{
  class Diatonic: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "diatonic"; }
  };
}
#endif //DIATONIC_H
