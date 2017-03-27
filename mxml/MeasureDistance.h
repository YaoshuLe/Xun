#ifndef MEASURE_DISTANCE_H
#define MEASURE_DISTANCE_H
#include "Element.h"

namespace mxml
{
  class MeasureDistance: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "measure-distance"; }
  };
}
#endif //MEASURE_DISTANCE_H
