#ifndef DAMP_ALL_H
#define DAMP_ALL_H
#include "EmptyPrintStyleAlign.h"

namespace mxml
{
  class DampAll: public EmptyPrintStyleAlign
  {
  public:
    virtual const char* tagname() const { return "damp-all"; }
  };
}
#endif //DAMP_ALL_H
