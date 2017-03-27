#ifndef PART_ABBREVIATION_DISPLAY_H
#define PART_ABBREVIATION_DISPLAY_H
#include "NameDisplay.h"

namespace mxml
{
  class PartAbbreviationDisplay: public NameDisplay
  {
  public:
    virtual const char* tagname() const { return "part-abbreviation-display"; }
  };
}
#endif //PART_ABBREVIATION_DISPLAY_H
