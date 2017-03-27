#ifndef STAFF_H
#define STAFF_H
#include "Element.h"

namespace mxml
{
  class Staff: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "staff"; }
  };
}
#endif //STAFF_H
