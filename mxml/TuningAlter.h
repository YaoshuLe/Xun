#ifndef TUNING_ALTER_H
#define TUNING_ALTER_H
#include "Element.h"

namespace mxml
{
  class TuningAlter: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "tuning-alter"; }
  };
}
#endif //TUNING_ALTER_H
