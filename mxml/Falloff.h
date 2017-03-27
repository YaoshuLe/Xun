#ifndef FALLOFF_H
#define FALLOFF_H
#include "EmptyLine.h"

namespace mxml
{
  class Falloff: public EmptyLine
  {
  public:
    virtual const char* tagname() const { return "falloff"; }
  };
}
#endif //FALLOFF_H
