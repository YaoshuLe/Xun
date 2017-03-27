#ifndef GROUP_ABBREVIATION_H
#define GROUP_ABBREVIATION_H
#include "GroupName.h"

namespace mxml
{
  class GroupAbbreviation: public GroupName
  {
  public:
    virtual const char* tagname() const { return "group-abbreviation"; }
  };
}
#endif //GROUP_ABBREVIATION_H
