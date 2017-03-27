#ifndef ALTER_H
#define ALTER_H
#include "Element.h"

namespace mxml
{
  class Alter: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "alter"; }
  };
}
#endif //ALTER_H
