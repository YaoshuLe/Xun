#ifndef PITCHED_H
#define PITCHED_H
#include "Element.h"

namespace mxml
{
  class Pitched: public Value<PitchedEnum>
  {
  public:
    virtual const char* tagname() const { return "pitched"; }
  };
}
#endif //PITCHED_H
