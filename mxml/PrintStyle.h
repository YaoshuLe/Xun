#ifndef PRINT_STYLE_H
#define PRINT_STYLE_H
#include "Position.h"
#include "Font.h"
#include "Color.h"

namespace mxml
{
  class PrintStyle: public Position, public Font, public Color
  {
  public:
    PrintStyle();
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //PRINT_STYLE_H
