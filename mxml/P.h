#ifndef P_H
#define P_H
#include "Element.h"

namespace mxml
{
  class P: public Empty
  {
  public:
    virtual const char* tagname() const { return "p"; }
  };
}
#endif //P_H
