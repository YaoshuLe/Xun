#ifndef RIGHT_DIVIDER_H
#define RIGHT_DIVIDER_H
#include "EmptyPrintObjectStyleAlign.h"

namespace mxml
{
  class RightDivider: public EmptyPrintObjectStyleAlign
  {
  public:
    virtual const char* tagname() const { return "right-divider"; }
  };
}
#endif //RIGHT_DIVIDER_H
