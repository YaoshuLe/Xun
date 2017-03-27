#ifndef SFFZ_H
#define SFFZ_H
#include "Element.h"

namespace mxml
{
  class Sffz: public Empty
  {
  public:
    virtual const char* tagname() const { return "sffz"; }
  };
}
#endif //SFFZ_H
