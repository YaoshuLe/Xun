#ifndef EMPTY_PRINT_STYLE_H
#define EMPTY_PRINT_STYLE_H
#include "Element.h"
#include "PrintStyle.h"

namespace mxml
{
  class EmptyPrintStyle: public Empty, public PrintStyle
  {
  public:
    EmptyPrintStyle();
    virtual const char* tagname() const { return "empty-print-style"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //EMPTY_PRINT_STYLE_H
