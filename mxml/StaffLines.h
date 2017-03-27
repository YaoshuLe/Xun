#ifndef STAFF_LINES_H
#define STAFF_LINES_H
#include "Element.h"

namespace mxml
{
  class StaffLines: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "staff-lines"; }
  };
}
#endif //STAFF_LINES_H
