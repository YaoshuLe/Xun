#ifndef OTHER_ORNAMENT_H
#define OTHER_ORNAMENT_H
#include "PlacementText.h"

namespace mxml
{
  class OtherOrnament: public PlacementText
  {
  public:
    virtual const char* tagname() const { return "other-ornament"; }
  };
}
#endif //OTHER_ORNAMENT_H
