#ifndef OTHER_TECHNICAL_H
#define OTHER_TECHNICAL_H
#include "PlacementText.h"

namespace mxml
{
  class OtherTechnical: public PlacementText
  {
  public:
    virtual const char* tagname() const { return "other-technical"; }
  };
}
#endif //OTHER_TECHNICAL_H
