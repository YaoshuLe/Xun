#ifndef TAP_H
#define TAP_H
#include "PlacementText.h"

namespace mxml
{
  class Tap: public PlacementText
  {
  public:
    virtual const char* tagname() const { return "tap"; }
  };
}
#endif //TAP_H
