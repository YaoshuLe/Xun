#ifndef STICK_LOCATION_H
#define STICK_LOCATION_H
#include "Element.h"

namespace mxml
{
  class StickLocation: public Value<StickLocationEnum>
  {
  public:
    virtual const char* tagname() const { return "stick-location"; }
  };
}
#endif //STICK_LOCATION_H
