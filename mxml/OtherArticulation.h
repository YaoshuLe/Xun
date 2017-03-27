#ifndef OTHER_ARTICULATION_H
#define OTHER_ARTICULATION_H
#include "PlacementText.h"

namespace mxml
{
  class OtherArticulation: public PlacementText
  {
  public:
    virtual const char* tagname() const { return "other-articulation"; }
  };
}
#endif //OTHER_ARTICULATION_H
