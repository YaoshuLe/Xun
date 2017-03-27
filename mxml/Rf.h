#ifndef RF_H
#define RF_H
#include "Element.h"

namespace mxml
{
  class Rf: public Empty
  {
  public:
    virtual const char* tagname() const { return "rf"; }
  };
}
#endif //RF_H
