#ifndef STACCATO_H
#define STACCATO_H
#include "EmptyPlacement.h"

namespace mxml
{
  class Staccato: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "staccato"; }
  };
}
#endif //STACCATO_H
