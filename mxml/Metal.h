#ifndef METAL_H
#define METAL_H
#include "Element.h"

namespace mxml
{
  class Metal: public Value<MetalEnum>
  {
  public:
    virtual const char* tagname() const { return "metal"; }
  };
}
#endif //METAL_H
