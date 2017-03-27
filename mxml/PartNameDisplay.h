#ifndef PART_NAME_DISPLAY_H
#define PART_NAME_DISPLAY_H
#include "NameDisplay.h"

namespace mxml
{
  class PartNameDisplay: public NameDisplay
  {
  public:
    virtual const char* tagname() const { return "part-name-display"; }
  };
}
#endif //PART_NAME_DISPLAY_H
