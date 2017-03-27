#ifndef PLOP_H
#define PLOP_H
#include "EmptyLine.h"

namespace mxml
{
  class Plop: public EmptyLine
  {
  public:
    virtual const char* tagname() const { return "plop"; }
  };
}
#endif //PLOP_H
