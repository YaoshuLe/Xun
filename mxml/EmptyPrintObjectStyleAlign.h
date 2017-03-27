#ifndef EMPTY_PRINT_OBJECT_STYLE_ALIGN_H
#define EMPTY_PRINT_OBJECT_STYLE_ALIGN_H
#include "Element.h"
#include "PrintObject.h"
#include "PrintStyleAlign.h"

namespace mxml
{
  class EmptyPrintObjectStyleAlign: public Empty, public PrintObject, public PrintStyleAlign
  {
  public:
    EmptyPrintObjectStyleAlign();
    virtual const char* tagname() const { return "empty-print-object-style-align"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //EMPTY_PRINT_OBJECT_STYLE_ALIGN_H
