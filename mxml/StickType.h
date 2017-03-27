#ifndef STICK_TYPE_H
#define STICK_TYPE_H
#include "Element.h"

namespace mxml
{
  class StickType: public Value<StickTypeEnum>
  {
  public:
    virtual const char* tagname() const { return "stick-type"; }
  };
}
#endif //STICK_TYPE_H
