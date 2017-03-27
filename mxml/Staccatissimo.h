#ifndef STACCATISSIMO_H
#define STACCATISSIMO_H
#include "EmptyPlacement.h"

namespace mxml
{
  class Staccatissimo: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "staccatissimo"; }
  };
}
#endif //STACCATISSIMO_H
