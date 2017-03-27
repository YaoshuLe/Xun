#ifndef PRINT_SPACING_H
#define PRINT_SPACING_H
#include "AttrGroup.h"

namespace mxml
{
  class PrintSpacing: public AttrGroup
  {
  public:
    PrintSpacing();
    bool hasPrintSpacing() const;
    void hasPrintSpacing(bool value);
    YesNoEnum printSpacing() const;
    void printSpacing(YesNoEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasPrintSpacing {false};
    YesNoEnum _printSpacing;
  };
}
#endif //PRINT_SPACING_H
