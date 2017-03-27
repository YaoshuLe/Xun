#ifndef EMPTY_PRINT_STYLE_ALIGN_H
#define EMPTY_PRINT_STYLE_ALIGN_H
#include "Element.h"
#include "PrintStyleAlign.h"

namespace mxml
{
  class EmptyPrintStyleAlign: public Empty, public PrintStyleAlign
  {
  public:
    EmptyPrintStyleAlign();
    virtual const char* tagname() const { return "empty-print-style-align"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //EMPTY_PRINT_STYLE_ALIGN_H
