#ifndef FZ_H
#define FZ_H
#include "Element.h"

namespace mxml
{
  class Fz: public Empty
  {
  public:
    virtual const char* tagname() const { return "fz"; }
  };
}
#endif //FZ_H
