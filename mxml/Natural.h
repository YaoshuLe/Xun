#ifndef NATURAL_H
#define NATURAL_H
#include "Element.h"

namespace mxml
{
  class Natural: public Empty
  {
  public:
    virtual const char* tagname() const { return "natural"; }
  };
}
#endif //NATURAL_H
