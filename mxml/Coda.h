#ifndef CODA_H
#define CODA_H
#include "EmptyPrintStyleAlign.h"

namespace mxml
{
  class Coda: public EmptyPrintStyleAlign
  {
  public:
    virtual const char* tagname() const { return "coda"; }
  };
}
#endif //CODA_H
