#ifndef TUNING_STEP_H
#define TUNING_STEP_H
#include "Element.h"

namespace mxml
{
  class TuningStep: public Value<StepEnum>
  {
  public:
    virtual const char* tagname() const { return "tuning-step"; }
  };
}
#endif //TUNING_STEP_H
