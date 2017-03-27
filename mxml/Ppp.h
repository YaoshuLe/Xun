#ifndef PPP_H
#define PPP_H
#include "Element.h"

namespace mxml
{
  class Ppp: public Empty
  {
  public:
    virtual const char* tagname() const { return "ppp"; }
  };
}
#endif //PPP_H
