#ifndef RFZ_H
#define RFZ_H
#include "Element.h"

namespace mxml
{
  class Rfz: public Empty
  {
  public:
    virtual const char* tagname() const { return "rfz"; }
  };
}
#endif //RFZ_H
