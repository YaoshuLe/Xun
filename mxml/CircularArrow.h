#ifndef CIRCULAR_ARROW_H
#define CIRCULAR_ARROW_H
#include "Element.h"

namespace mxml
{
  class CircularArrow: public Value<CircularArrowEnum>
  {
  public:
    virtual const char* tagname() const { return "circular-arrow"; }
  };
}
#endif //CIRCULAR_ARROW_H
