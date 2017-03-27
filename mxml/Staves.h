#ifndef STAVES_H
#define STAVES_H
#include "Element.h"

namespace mxml
{
  class Staves: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "staves"; }
  };
}
#endif //STAVES_H
