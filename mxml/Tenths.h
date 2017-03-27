#ifndef TENTHS_H
#define TENTHS_H
#include "Element.h"

namespace mxml
{
  class Tenths: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "tenths"; }
  };
}
#endif //TENTHS_H
