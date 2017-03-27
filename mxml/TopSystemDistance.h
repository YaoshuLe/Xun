#ifndef TOP_SYSTEM_DISTANCE_H
#define TOP_SYSTEM_DISTANCE_H
#include "Element.h"

namespace mxml
{
  class TopSystemDistance: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "top-system-distance"; }
  };
}
#endif //TOP_SYSTEM_DISTANCE_H
