#ifndef DIVISIONS_H
#define DIVISIONS_H
#include "Element.h"

namespace mxml
{
  class Divisions: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "divisions"; }
  };
}
#endif //DIVISIONS_H
