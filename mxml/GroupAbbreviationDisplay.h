#ifndef GROUP_ABBREVIATION_DISPLAY_H
#define GROUP_ABBREVIATION_DISPLAY_H
#include "NameDisplay.h"

namespace mxml
{
  class GroupAbbreviationDisplay: public NameDisplay
  {
  public:
    virtual const char* tagname() const { return "group-abbreviation-display"; }
  };
}
#endif //GROUP_ABBREVIATION_DISPLAY_H
