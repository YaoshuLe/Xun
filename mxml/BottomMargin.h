#ifndef BOTTOM_MARGIN_H
#define BOTTOM_MARGIN_H
#include "Element.h"

namespace mxml
{
  class BottomMargin: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "bottom-margin"; }
  };
}
#endif //BOTTOM_MARGIN_H
