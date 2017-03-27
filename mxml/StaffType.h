#ifndef STAFF_TYPE_H
#define STAFF_TYPE_H
#include "Element.h"

namespace mxml
{
  class StaffType: public Value<StaffTypeEnum>
  {
  public:
    virtual const char* tagname() const { return "staff-type"; }
  };
}
#endif //STAFF_TYPE_H
