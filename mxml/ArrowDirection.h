#ifndef ARROW_DIRECTION_H
#define ARROW_DIRECTION_H
#include "Element.h"

namespace mxml
{
  class ArrowDirection: public Value<ArrowDirectionEnum>
  {
  public:
    virtual const char* tagname() const { return "arrow-direction"; }
  };
}
#endif //ARROW_DIRECTION_H
