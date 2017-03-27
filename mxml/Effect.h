#ifndef EFFECT_H
#define EFFECT_H
#include "Element.h"

namespace mxml
{
  class Effect: public Value<EffectEnum>
  {
  public:
    virtual const char* tagname() const { return "effect"; }
  };
}
#endif //EFFECT_H
