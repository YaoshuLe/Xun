#ifndef PLUCK_H
#define PLUCK_H
#include "PlacementText.h"

namespace mxml
{
  class Pluck: public PlacementText
  {
  public:
    virtual const char* tagname() const { return "pluck"; }
  };
}
#endif //PLUCK_H
