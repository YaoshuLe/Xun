#ifndef END_LINE_H
#define END_LINE_H
#include "Element.h"

namespace mxml
{
  class EndLine: public Empty
  {
  public:
    virtual const char* tagname() const { return "end-line"; }
  };
}
#endif //END_LINE_H
