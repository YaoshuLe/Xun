#ifndef UNSTRESS_H
#define UNSTRESS_H
#include "EmptyPlacement.h"

namespace mxml
{
  class Unstress: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "unstress"; }
  };
}
#endif //UNSTRESS_H
