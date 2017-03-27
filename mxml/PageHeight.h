#ifndef PAGE_HEIGHT_H
#define PAGE_HEIGHT_H
#include "Element.h"

namespace mxml
{
  class PageHeight: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "page-height"; }
  };
}
#endif //PAGE_HEIGHT_H
