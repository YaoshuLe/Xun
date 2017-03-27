#ifndef DISPLAY_STEP_H
#define DISPLAY_STEP_H
#include "Element.h"

namespace mxml
{
  class DisplayStep: public Value<StepEnum>
  {
  public:
    virtual const char* tagname() const { return "display-step"; }
  };
}
#endif //DISPLAY_STEP_H
