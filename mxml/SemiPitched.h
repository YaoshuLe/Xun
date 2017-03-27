#ifndef SEMI_PITCHED_H
#define SEMI_PITCHED_H
#include "Element.h"

namespace mxml
{
  class SemiPitched: public Value<SemiPitchedEnum>
  {
  public:
    virtual const char* tagname() const { return "semi-pitched"; }
  };
}
#endif //SEMI_PITCHED_H
