#ifndef PEDAL_STEP_H
#define PEDAL_STEP_H
#include "Element.h"

namespace mxml
{
  class PedalStep: public Value<StepEnum>
  {
  public:
    virtual const char* tagname() const { return "pedal-step"; }
  };
}
#endif //PEDAL_STEP_H
