#ifndef STAFF_DISTANCE_H
#define STAFF_DISTANCE_H
#include "Element.h"

namespace mxml
{
  class StaffDistance: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "staff-distance"; }
  };
}
#endif //STAFF_DISTANCE_H
