#ifndef STAFF_SIZE_H
#define STAFF_SIZE_H
#include "Element.h"

namespace mxml
{
  class StaffSize: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "staff-size"; }
  };
}
#endif //STAFF_SIZE_H
