#ifndef MF_H
#define MF_H
#include "Element.h"

namespace mxml
{
  class Mf: public Empty
  {
  public:
    virtual const char* tagname() const { return "mf"; }
  };
}
#endif //MF_H
