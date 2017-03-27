#ifndef PRINT_STYLE_ALIGN_H
#define PRINT_STYLE_ALIGN_H
#include "PrintStyle.h"
#include "Halign.h"
#include "Valign.h"

namespace mxml
{
  class PrintStyleAlign: public PrintStyle, public Halign, public Valign
  {
  public:
    PrintStyleAlign();
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //PRINT_STYLE_ALIGN_H
