#ifndef EYEGLASSES_H
#define EYEGLASSES_H
#include "EmptyPrintStyleAlign.h"

namespace mxml
{
  class Eyeglasses: public EmptyPrintStyleAlign
  {
  public:
    virtual const char* tagname() const { return "eyeglasses"; }
  };
}
#endif //EYEGLASSES_H
