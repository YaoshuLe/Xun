#ifndef F_H
#define F_H
#include "Element.h"

namespace mxml
{
  class F: public Empty
  {
  public:
    virtual const char* tagname() const { return "f"; }
  };
}
#endif //F_H
