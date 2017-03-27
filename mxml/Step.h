#ifndef STEP_H
#define STEP_H
#include "Element.h"

namespace mxml
{
  class Step: public Value<StepEnum>
  {
  public:
    virtual const char* tagname() const { return "step"; }
  };
}
#endif //STEP_H
