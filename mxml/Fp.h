#ifndef FP_H
#define FP_H
#include "Element.h"

namespace mxml
{
  class Fp: public Empty
  {
  public:
    virtual const char* tagname() const { return "fp"; }
  };
}
#endif //FP_H
