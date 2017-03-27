#ifndef GROUP_NAME_DISPLAY_H
#define GROUP_NAME_DISPLAY_H
#include "NameDisplay.h"

namespace mxml
{
  class GroupNameDisplay: public NameDisplay
  {
  public:
    virtual const char* tagname() const { return "group-name-display"; }
  };
}
#endif //GROUP_NAME_DISPLAY_H
