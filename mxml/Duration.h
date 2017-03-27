#ifndef DURATION_H
#define DURATION_H
#include "Element.h"

namespace mxml
{
  class Duration: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "duration"; }
  };
}
#endif //DURATION_H
