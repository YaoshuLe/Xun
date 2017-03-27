#ifndef SFZ_H
#define SFZ_H
#include "Element.h"

namespace mxml
{
  class Sfz: public Empty
  {
  public:
    virtual const char* tagname() const { return "sfz"; }
  };
}
#endif //SFZ_H
