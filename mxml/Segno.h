#ifndef SEGNO_H
#define SEGNO_H
#include "EmptyPrintStyleAlign.h"

namespace mxml
{
  class Segno: public EmptyPrintStyleAlign
  {
  public:
    virtual const char* tagname() const { return "segno"; }
  };
}
#endif //SEGNO_H
