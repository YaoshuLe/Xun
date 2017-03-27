#ifndef SCOOP_H
#define SCOOP_H
#include "EmptyLine.h"

namespace mxml
{
  class Scoop: public EmptyLine
  {
  public:
    virtual const char* tagname() const { return "scoop"; }
  };
}
#endif //SCOOP_H
