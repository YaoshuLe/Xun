#ifndef BAR_STYLE_H
#define BAR_STYLE_H
#include "BarStyleColor.h"

namespace mxml
{
  class BarStyle: public BarStyleColor
  {
  public:
    virtual const char* tagname() const { return "bar-style"; }
  };
}
#endif //BAR_STYLE_H
