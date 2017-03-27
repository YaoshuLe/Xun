#ifndef LEFT_DIVIDER_H
#define LEFT_DIVIDER_H
#include "EmptyPrintObjectStyleAlign.h"

namespace mxml
{
  class LeftDivider: public EmptyPrintObjectStyleAlign
  {
  public:
    virtual const char* tagname() const { return "left-divider"; }
  };
}
#endif //LEFT_DIVIDER_H
