#ifndef MILLIMETERS_H
#define MILLIMETERS_H
#include "Element.h"

namespace mxml
{
  class Millimeters: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "millimeters"; }
  };
}
#endif //MILLIMETERS_H
