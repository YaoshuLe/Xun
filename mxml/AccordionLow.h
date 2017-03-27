#ifndef ACCORDION_LOW_H
#define ACCORDION_LOW_H
#include "Element.h"

namespace mxml
{
  class AccordionLow: public Empty
  {
  public:
    virtual const char* tagname() const { return "accordion-low"; }
  };
}
#endif //ACCORDION_LOW_H
