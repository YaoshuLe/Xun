#ifndef VOLUME_H
#define VOLUME_H
#include "Element.h"

namespace mxml
{
  class Volume: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "volume"; }
  };
}
#endif //VOLUME_H
