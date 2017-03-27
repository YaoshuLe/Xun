#ifndef HOLE_SHAPE_H
#define HOLE_SHAPE_H
#include "Element.h"

namespace mxml
{
  class HoleShape: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "hole-shape"; }
  };
}
#endif //HOLE_SHAPE_H
