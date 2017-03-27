#ifndef LEFT_MARGIN_H
#define LEFT_MARGIN_H
#include "Element.h"

namespace mxml
{
  class LeftMargin: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "left-margin"; }
  };
}
#endif //LEFT_MARGIN_H
