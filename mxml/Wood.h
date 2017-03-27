#ifndef WOOD_H
#define WOOD_H
#include "Element.h"

namespace mxml
{
  class Wood: public Value<WoodEnum>
  {
  public:
    virtual const char* tagname() const { return "wood"; }
  };
}
#endif //WOOD_H
