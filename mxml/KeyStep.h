#ifndef KEY_STEP_H
#define KEY_STEP_H
#include "Element.h"

namespace mxml
{
  class KeyStep: public Value<StepEnum>
  {
  public:
    virtual const char* tagname() const { return "key-step"; }
  };
}
#endif //KEY_STEP_H
