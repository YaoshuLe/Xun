#ifndef EMPTY_LINE_H
#define EMPTY_LINE_H
#include "Element.h"
#include "LineShape.h"
#include "LineType.h"
#include "DashedFormatting.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class EmptyLine: public Empty, public LineShape, public LineType, public DashedFormatting, public PrintStyle, public Placement
  {
  public:
    EmptyLine();
    virtual const char* tagname() const { return "empty-line"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //EMPTY_LINE_H
