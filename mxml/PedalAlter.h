#ifndef PEDAL_ALTER_H
#define PEDAL_ALTER_H
#include "Element.h"

namespace mxml
{
  class PedalAlter: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "pedal-alter"; }
  };
}
#endif //PEDAL_ALTER_H
