#ifndef FIFTHS_H
#define FIFTHS_H
#include "Element.h"

namespace mxml
{
  class Fifths: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "fifths"; }
  };
}
#endif //FIFTHS_H
