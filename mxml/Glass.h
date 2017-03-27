#ifndef GLASS_H
#define GLASS_H
#include "Element.h"

namespace mxml
{
  class Glass: public Value<GlassEnum>
  {
  public:
    virtual const char* tagname() const { return "glass"; }
  };
}
#endif //GLASS_H
