#ifndef PART_ABBREVIATION_H
#define PART_ABBREVIATION_H
#include "PartName.h"

namespace mxml
{
  class PartAbbreviation: public PartName
  {
  public:
    virtual const char* tagname() const { return "part-abbreviation"; }
  };
}
#endif //PART_ABBREVIATION_H
