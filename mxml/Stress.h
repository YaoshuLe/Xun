#ifndef STRESS_H
#define STRESS_H
#include "EmptyPlacement.h"

namespace mxml
{
  class Stress: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "stress"; }
  };
}
#endif //STRESS_H
