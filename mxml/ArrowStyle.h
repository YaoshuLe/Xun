#ifndef ARROW_STYLE_H
#define ARROW_STYLE_H
#include "Element.h"

namespace mxml
{
  class ArrowStyle: public Value<ArrowStyleEnum>
  {
  public:
    virtual const char* tagname() const { return "arrow-style"; }
  };
}
#endif //ARROW_STYLE_H
