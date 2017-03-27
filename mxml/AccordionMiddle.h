#ifndef ACCORDION_MIDDLE_H
#define ACCORDION_MIDDLE_H
#include "Element.h"

namespace mxml
{
  class AccordionMiddle: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "accordion-middle"; }
  };
}
#endif //ACCORDION_MIDDLE_H
