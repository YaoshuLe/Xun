#ifndef INSTRUMENTS_H
#define INSTRUMENTS_H
#include "Element.h"

namespace mxml
{
  class Instruments: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "instruments"; }
  };
}
#endif //INSTRUMENTS_H
