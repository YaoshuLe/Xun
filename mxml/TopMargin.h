#ifndef TOP_MARGIN_H
#define TOP_MARGIN_H
#include "Element.h"

namespace mxml
{
  class TopMargin: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "top-margin"; }
  };
}
#endif //TOP_MARGIN_H
