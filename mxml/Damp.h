#ifndef DAMP_H
#define DAMP_H
#include "EmptyPrintStyleAlign.h"

namespace mxml
{
  class Damp: public EmptyPrintStyleAlign
  {
  public:
    virtual const char* tagname() const { return "damp"; }
  };
}
#endif //DAMP_H
