#ifndef ELEVATION_H
#define ELEVATION_H
#include "Element.h"

namespace mxml
{
  class Elevation: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "elevation"; }
  };
}
#endif //ELEVATION_H
