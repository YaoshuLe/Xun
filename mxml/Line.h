#ifndef LINE_H
#define LINE_H
#include "Element.h"

namespace mxml
{
  class Line: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "line"; }
  };
}
#endif //LINE_H
