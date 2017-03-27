#ifndef WITH_BAR_H
#define WITH_BAR_H
#include "PlacementText.h"

namespace mxml
{
  class WithBar: public PlacementText
  {
  public:
    virtual const char* tagname() const { return "with-bar"; }
  };
}
#endif //WITH_BAR_H
