#ifndef OPEN_STRING_H
#define OPEN_STRING_H
#include "EmptyPlacement.h"

namespace mxml
{
  class OpenString: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "open-string"; }
  };
}
#endif //OPEN_STRING_H
