#ifndef DOIT_H
#define DOIT_H
#include "EmptyLine.h"

namespace mxml
{
  class Doit: public EmptyLine
  {
  public:
    virtual const char* tagname() const { return "doit"; }
  };
}
#endif //DOIT_H
