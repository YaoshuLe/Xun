#ifndef SYSTEM_DISTANCE_H
#define SYSTEM_DISTANCE_H
#include "Element.h"

namespace mxml
{
  class SystemDistance: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "system-distance"; }
  };
}
#endif //SYSTEM_DISTANCE_H
