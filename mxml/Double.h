#ifndef DOUBLE_H
#define DOUBLE_H
#include "Element.h"

namespace mxml
{
  class Double: public Empty
  {
  public:
    virtual const char* tagname() const { return "double"; }
  };
}
#endif //DOUBLE_H
