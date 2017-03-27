#ifndef MP_H
#define MP_H
#include "Element.h"

namespace mxml
{
  class Mp: public Empty
  {
  public:
    virtual const char* tagname() const { return "mp"; }
  };
}
#endif //MP_H
