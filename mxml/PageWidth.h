#ifndef PAGE_WIDTH_H
#define PAGE_WIDTH_H
#include "Element.h"

namespace mxml
{
  class PageWidth: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "page-width"; }
  };
}
#endif //PAGE_WIDTH_H
