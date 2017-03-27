#ifndef NORMAL_DOT_H
#define NORMAL_DOT_H
#include "Element.h"

namespace mxml
{
  class NormalDot: public Empty
  {
  public:
    virtual const char* tagname() const { return "normal-dot"; }
  };
}
#endif //NORMAL_DOT_H
