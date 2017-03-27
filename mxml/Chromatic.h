#ifndef CHROMATIC_H
#define CHROMATIC_H
#include "Element.h"

namespace mxml
{
  class Chromatic: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "chromatic"; }
  };
}
#endif //CHROMATIC_H
