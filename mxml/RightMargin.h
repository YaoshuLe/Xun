#ifndef RIGHT_MARGIN_H
#define RIGHT_MARGIN_H
#include "Element.h"

namespace mxml
{
  class RightMargin: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "right-margin"; }
  };
}
#endif //RIGHT_MARGIN_H
