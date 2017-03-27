#ifndef MEMBRANE_H
#define MEMBRANE_H
#include "Element.h"

namespace mxml
{
  class Membrane: public Value<MembraneEnum>
  {
  public:
    virtual const char* tagname() const { return "membrane"; }
  };
}
#endif //MEMBRANE_H
