#ifndef TRIPLE_TONGUE_H
#define TRIPLE_TONGUE_H
#include "EmptyPlacement.h"

namespace mxml
{
  class TripleTongue: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "triple-tongue"; }
  };
}
#endif //TRIPLE_TONGUE_H
