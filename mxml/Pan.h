#ifndef PAN_H
#define PAN_H
#include "Element.h"

namespace mxml
{
  class Pan: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "pan"; }
  };
}
#endif //PAN_H
