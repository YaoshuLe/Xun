#ifndef GROUP_TIME_H
#define GROUP_TIME_H
#include "Element.h"

namespace mxml
{
  class GroupTime: public Empty
  {
  public:
    virtual const char* tagname() const { return "group-time"; }
  };
}
#endif //GROUP_TIME_H
