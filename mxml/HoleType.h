#ifndef HOLE_TYPE_H
#define HOLE_TYPE_H
#include "Element.h"

namespace mxml
{
  class HoleType: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "hole-type"; }
  };
}
#endif //HOLE_TYPE_H
