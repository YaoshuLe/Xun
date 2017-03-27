#ifndef CAESURA_H
#define CAESURA_H
#include "EmptyPlacement.h"

namespace mxml
{
  class Caesura: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "caesura"; }
  };
}
#endif //CAESURA_H
